//
//  map_matrix.c
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

int		is_map_beggining(char *line)
{
	char *trimmed;
	char *secondTrimmed;
	
	trimmed = ft_strtrim(line, " ");
	secondTrimmed = ft_strtrim(trimmed, "0");
	if (secondTrimmed[0] == '1')
		return 1;
	return 0;
}

void	get_map_max_height(char *raw_map, t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open("map0.cub", O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_map_beggining(line))
			i++;
			
		free(line);
	}
	close(fd);
	map->map_height = i;
}

void	get_map_max_widht(char *raw_map, t_map *map)
{
	int		fd;
	int		i;
	int		max_width;
	char	*line;
	
	fd = open("map0.cub", O_RDONLY);
	max_width = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_map_beggining(line))
		{
			i = 0;
			while (line[i])
				i++;
			if (i > max_width)
				max_width = i;
		}
			
		free(line);
	}
	close(fd);
	map->map_width = max_width;
}

void	save_mapfile_in_map(char *raw_map, t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open("map0.cub", O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_map_beggining(line))
		{
			i = 0;
			while (line[i])
				map->map[j++] = line[i++];
			while (i++ < map->map_width)
				map->map[j++] = '8';
			map->map[j++] = '\n';
		}
		free(line);
	}
	map->map[j - 1] = '\0';
	close(fd);
}

void	replace_spaces_in_map(t_map *map)
{
	int i;
	
	i = 0;
	while (map->map[i]) {
		if (map->map[i] == ' ')
			map->map[i] = '8';
		i++;
	}
}

void	parse_map(char *raw_map, t_map *map)
{
	get_map_max_height(raw_map, map);
	get_map_max_widht(raw_map, map);
	
	if (!(map->map = (char*)malloc(sizeof(*map) * (map->map_height * map->map_width))))
		print_error("Map parsing allocation gone wrong.");
	
	save_mapfile_in_map(raw_map, map);
	replace_spaces_in_map(map);
	printf("%s", map->map);

}
