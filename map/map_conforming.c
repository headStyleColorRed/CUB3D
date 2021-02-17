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
	if (!map->map_textures.NO_texture || !map->map_textures.SO_texture || !map->map_textures.WE_texture || !map->map_textures.EA_texture || !map->map_textures.SP_texture)
		print_error("One of the textures is missing.");
}

void	check_resolution_conformity(t_map *map)
{
	if (map->resolution.height < MIN_SCREEN_HEIGHT )
		print_error("Screen height resolution is less than 100");
	if (map->resolution.height > MAX_SCREEN_HEIGHT)
		print_error("Screen height resolution is greater than 1440");
	if (map->resolution.width < MIN_SCREEN_HEIGHT )
		print_error("Screen width resolution is less than 100");
	if (map->resolution.width > MAX_SCREEN_WIDTH)
		print_error("Screen width resolution is greater than 2560");
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

void	check_only_one_player_position(t_map *map)
{
	int		i;
	int		player_position;

	i = 0;
	player_position = 0;
	while(map->map[i])
	{
		if (ft_check_if_character(map->map[i], "NSWE"))
			player_position++;
		i++;
	}
	if (player_position > 1)
		print_error("More than one player position found");
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
	check_all_fields_are_present(map);
	check_texture_conformity(map);
	check_resolution_conformity(map);
	check_map_right_left_conformity(map);
	check_map_top_bottom_conformity(map);
	check_map_player_position(map);
	check_for_forbidden_characters(map);
	check_only_one_player_position(map);
}
