//
//  map_spaced_matrix.c
//  Wolfenstein
//
//  Created by Rodrigo  on 15/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

int		is_spaced_map_beggining(char *line)
{
	char *trimmed;
	char *secondTrimmed;
	
	trimmed = ft_strtrim(line, " ");
	secondTrimmed = ft_strtrim(trimmed, "0");
	if (secondTrimmed[0] == '1')
		return 1;
	return 0;
}

void	get_spaced_map_max_height(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open(map->map_file, O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_spaced_map_beggining(line))
			i++;
			
		free(line);
	}
	close(fd);
	map->map_height = i;
}

void	get_spaced_map_max_widht(t_map *map)
{
	int		fd;
	int		i;
	int		max_width;
	int		symbols;
	char	*line;
	t_bool	map_has_begun;
	
	fd = open(map->map_file, O_RDONLY);
	max_width = 0;
	map_has_begun = ft_false;
	symbols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_spaced_map_beggining(line))
		{
			map_has_begun = ft_true;
			i = 0;
			while (line[i]){
				if (line[i] != ' ')
					symbols++;
				i++;
			}
			if (symbols > max_width)
				max_width = symbols;
			symbols = 0;
		} else if (map_has_begun == ft_true)
			print_error("Map has a rotten line");
		
		free(line);
	}
	close(fd);
	map->map_width = max_width;
}

void	save_mapfile_in_spaced_map(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open(map->map_file, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_spaced_map_beggining(line))
		{
			i = 0;
			while (line[i])
			{
				if (line[i] != ' ')
					map->map[j++] = line[i];
				i++;
			}
			while (i++ < map->map_width)
				map->map[j++] = '8';
			map->map[j++] = '\n';
		}
		free(line);
	}
	map->map[j - 1] = '\0';
	close(fd);
}

void	replace_spaces_in_spaced_map(t_map *map)
{
	int i;
	
	i = 0;
	while (map->map[i]) {
		if (map->map[i] == ' ')
			map->map[i] = '8';
		i++;
	}
}

void	parse_spaced_map(t_map *map)
{
	get_spaced_map_max_height(map);
	get_spaced_map_max_widht(map);
	
	if (!(map->map = (char*)malloc(sizeof(*map) * (map->map_height * map->map_width))))
		print_error("Map parsing allocation gone wrong.");
	
	save_mapfile_in_spaced_map(map);
}
