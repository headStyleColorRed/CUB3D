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
	if (map->resolution.length <= 0 || map->resolution.width <= 0)
		print_error("Either one of the resolutions was 0");
}

int		check_map_player_position(t_map *map)
{
	int		i;
	
	i = 0;
	while(map->map[i])
	{
		if (ft_check_if_character(map->map[i], "NSWE"))
			return (1);
		i++;
	}
	print_error("No player position found");
	return (0);
}

void	check_for_forbidden_characters(t_map *map)
{
	int		i;
	
	i = 0;
	while(map->map[i])
	{
		if (!ft_check_if_character(map->map[i], "NSWE0128\n"))
			print_error("Extraneus character in map");
		i++;
	}
}

void	check_file_conformity(t_map *map)
{
	check_texture_conformity(map);
	check_resolution_conformity(map);
	check_map_right_left_conformity(map);
	check_map_top_conformity(map);
	check_map_bottom_conformity(map);
	check_map_player_position(map);
	check_for_forbidden_characters(map);
	
}
