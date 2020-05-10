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
 
	parse_resolution() ->
			1. Gets the raw string with the values we need
			2. Splits the line in three and assignes the 2º and 3º field to
				the width and length of the screen
 
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

void	parse_resolution(char *raw_map, t_map *map)
{
	char *resolutions;
	char **splitted_resolutions;
	
	resolutions = parse_character(raw_map, map_textures("RESOLUTION"));
	if (!resolutions)
		print_error("Resolutions field not found.");
	
	splitted_resolutions = ft_split(resolutions, ' ');
	map->resolution.width = ft_atoi(splitted_resolutions[1]);
	map->resolution.length = ft_atoi(splitted_resolutions[2]);
	
}
