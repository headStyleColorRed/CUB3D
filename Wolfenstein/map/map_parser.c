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
			3. Returns the cutted line.
 
 */

char	*parse_character(char *raw_map, char *chosen_field)
{
	char	*partial_string;
	
	partial_string = ft_strstr(raw_map, chosen_field);
	return ft_split(partial_string, '\n')[0];
	
}

void	parse_resolution(char *raw_map)
{
	char *i;
	
	i = parse_character(raw_map, map_textures("EAST"));
	printf("%s", i);
	
}
