//
//  map_parser.c
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"
/*
 parse_character() ->
 1. Gets the begining of the string and stores the result in partial_string.
 2. Copies in final_string the whole line until it reaches a new line character.
 3. Returns either the cutted line or null if field not found.

 */

char	*parse_character(char *raw_map, char *chosen_field)
{
	char	*partial_string;

	partial_string = ft_strstr(raw_map, chosen_field);
	if (ft_split(partial_string, '\n') != NULL)
		return ft_split(partial_string, '\n')[0];
	else
		return NULL;
}

void initialize_map_values(t_map *map)
{
	map->map_textures.NO_texture = NULL;
	map->map_textures.SO_texture = NULL;
	map->map_textures.WE_texture = NULL;
	map->map_textures.EA_texture = NULL;
	map->map_textures.SP_texture = NULL;
	map->resolution.height = 0;
	map->resolution.width = 0;
	map->floor_color.r_color = 0;
	map->floor_color.g_color = 0;
	map->floor_color.b_color = 0;
	map->ceiling_color.r_color = 0;
	map->ceiling_color.g_color = 0;
	map->ceiling_color.b_color = 0;
}

int map_has_spaces(t_map *map)
{
	int i;
	int		fd;
	int		spaces;
	char	*line;

	fd = open(map->map_file, O_RDONLY);
	i = 0;
	spaces = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_map_beggining(line))
		{
			i = 0;
			while (line[i])
			{
				if (ft_isdigit(line[i]) && line[i + 1] == ' ')
					spaces++;
				i++;
			}

		}
		free(line);
	}
	close(fd);
	if (spaces > 5)
		return (1);
	return (0);
}

void	parse_cube_map(char *raw_map, t_map *map)
{
	initialize_map_values(map);
	parse_resolution(raw_map, map);
	parse_north_texture(raw_map, map);
	parse_south_texture(raw_map, map);
	parse_west_texture(raw_map, map);
	parse_east_texture(raw_map, map);
	parse_sprite_texture(raw_map, map);
	parse_floor_color(raw_map, map);
	parse_ceiling_color(raw_map, map);
	map_has_spaces(map) ? parse_spaced_map(map) : parse_map(map);
}
