//
//  map_conforming.c
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

void	check_texture_conformity(t_map *map)
{
	if (!map->NO_texture || !map->SO_texture || !map->WE_texture || !map->EA_texture || !map->SP_texture)
		print_error("One of the textures is missing.");
}

void	check_resolution_conformity(t_map *map)
{
	if (map->resolution.length == 0 || map->resolution.width == 0)
		print_error("Either one of the resolutions was 0");
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
		if (map->map[i] == '-' && map->map[i-1] != '1')
			print_error(error_string);
		if (map->map[i] == '-' && map->map[i+1] != '1')
			print_error(error_string);
	}
	
}

int		check_next_line(int i, t_map *map)
{
	int position_in_next_line;
	
	position_in_next_line = map->map[i + map->map_width + 1];
	if (position_in_next_line == '8' && (i + map->map_width + 1) < ft_strlen(map->map))
		check_next_line(i + map->map_width + 1, map);
	
	return (1);
}

void	check_map_top_bottom_conformity(t_map *map)
{
	int		i;
	int		j;
	char	*error_string;
	
	i = 0;
	j = 0;
	error_string = "Map was missing a top/bottom 1";
	while(map->map[i++] != '\n')
	{
		if (map->map[i] != '1' && map->map[i] != '8' )
			print_error(error_string);
		
		if (map->map[i] != '1')
		{
			if (!check_next_line(i, map))
				print_error(error_string);
		}
	}
	
}

void	check_file_conformity(t_map *map)
{
	check_texture_conformity(map);
	check_resolution_conformity(map);
	check_map_right_left_conformity(map);
	check_map_top_bottom_conformity(map);
	
}
