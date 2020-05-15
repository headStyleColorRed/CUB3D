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

void	check_map_right_left_conformity(t_map *map)
{
	int		i;
	char	*error_string;
	
	i = 0;
	error_string = "Map was missing a right/left 1";
	if (map->map[i] != '1')
		print_error(error_string);
	while(map->map[i++])
	{
		if (map->map[i] == '\n' && map->map[i-1] != '1')
			check_map_previous_character(i, map);
		if (map->map[i] == '\n' && map->map[i+1] != '1')
			check_map_next_character(i + 1, map);
	}
	
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

void	check_map_top_conformity(t_map *map)
{
	int		i;
	
	i = 0;
	while(map->map[i] != '\n')
	{
		if (!ft_check_if_character(map->map[i], "18\n"))
			print_error("Map was missing a top 1");
		
		if (map->map[i] != '1')
			check_next_line(i, map);
		i++;
	}
	
}

void	check_map_bottom_conformity(t_map *map)
{
	int		i;
	
	i = ft_strlen(map->map) - 1;
	while(map->map[i] != '\n')
	{
		if (!ft_check_if_character(map->map[i], "18\n"))
			print_error("Map was missing a bottom 1");
		
		if (map->map[i] != '1')
			check_past_line(i, map);
		i--;
	}
	
	
}
