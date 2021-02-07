//
//  map_confoming_map.c
//  Wolfenstein
//
//  Created by Rodrigo  on 15/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

void	check_map_previous_character(int i, t_map *map)
{
	if (map->map[i] == '8')
		check_map_previous_character(i - 1, map);
	else if (map->map[i] != '1')
		print_error("Map was missing a right 1");
}

void	check_map_next_character(int i, t_map *map)
{
	if (map->map[i] == '8')
		check_map_next_character(i + 1, map);
	else if (map->map[i] != '1')
		print_error("Map was missing a left 1");
}

void	check_map_right_conformity(char *line)
{
	int		i;

	i = 0;
	while(line[i] == '8')
		i++;
	if(line[i] != '1')
		print_error("Found missing left wall (1)");
}

void	check_map_left_conformity(char *line)
{
	int		i;

	i = ft_strlen(line) - 1;
	while(line[i] == '8')
		i--;
	if(line[i] != '1')
		print_error("Found missing right wall (1)");
}

void	check_map_right_left_conformity(t_map *map)
{
	char *temp_line;
	int i;
	int j;

	i = 0;
	j = 0;
	temp_line = ft_calloc(500, 1);
	while (map->map[i] != '\0')
	{
		if (map->map[i] == '\n')
		{
			check_map_right_conformity(temp_line);
			check_map_left_conformity(temp_line);
			ft_bzero(temp_line, 500);
			j = 0;
			i++;
		}
		temp_line[j++] = map->map[i];
		i++;
	}
	free(temp_line);
}

int		check_next_line(int i, t_map *map)
{
	int position_in_next_line;

	position_in_next_line = map->map[i + map->map_width + 1];
	if (position_in_next_line == '8' && (i + map->map_width + 1) < ft_strlen(map->map))
		check_next_line(i + map->map_width + 1, map);
	else if (!ft_check_if_character(position_in_next_line, "1\n"))
		print_error("Map was missing a top 1");
	return (1);
}

int		check_past_line(int i, t_map *map)
{
	int position_in_next_line;

	position_in_next_line = map->map[i - map->map_width - 1];
	if (position_in_next_line == '8' && (i - map->map_width - 1) < ft_strlen(map->map))
		check_past_line(i - map->map_width - 1, map);
	else if (!ft_check_if_character(position_in_next_line, "1\n"))
		print_error("Map was missing a bottom 1");
	return (1);
}

void	check_map_top_conformity(char *line)
{
	int		i;

	i = 0;
	while(line[i] == '8')
		i++;
	if(line[i] != '1' && line[i] != '\0')
		print_error("Found missing top wall (1)");
}

void	check_map_bottom_conformity(char *line)
{
	int		i;

	i = ft_strlen(line) - 1;
	while(line[i] == '8' && i > 0)
		i--;
	if(line[i] != '1' && i != 0)
		print_error("Found missing bottom wall (1)");
}

void	check_map_top_bottom_conformity(t_map *map)
{
	char	*temp_line;
	int		width;
	int		heigth;
	int		i;
	int		total_length;

	width = 0;
	heigth = 0;
	i = 0;
	total_length = ft_strlen(map->map);
	temp_line = ft_calloc(map->map_height * 2, 1);
	while(width < map->map_width)
	{
		while(heigth < total_length)
		{
			temp_line[i++] = map->map[heigth + width];
			heigth += map->map_width + 1;
		}
		check_map_top_conformity(temp_line);
		check_map_bottom_conformity(temp_line);
		heigth = 0;
		i = 0;
		ft_bzero(temp_line, map->map_height * 2);
		width++;
	}


	free(temp_line);
}


