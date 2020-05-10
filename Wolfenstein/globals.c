//
//  globals.c
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "library.h"

char	*map_textures(char *chosen_map)
{
	if (!ft_strncmp(chosen_map, "NORTH", 4))
		return "NO";
	else if (!ft_strncmp(chosen_map, "SOUTH", 4))
		return "SO";
	else if (!ft_strncmp(chosen_map, "WEST", 4))
		return "WE";
	else if (!ft_strncmp(chosen_map, "EAST", 4))
		return "EA";
	else if (!ft_strncmp(chosen_map, "RESOLUTION", 4))
		return "R";
	else if (!ft_strncmp(chosen_map, "SPRITE", 4))
		return "S";
	else if (!ft_strncmp(chosen_map, "FLOOR", 4))
		return "F";
	else if (!ft_strncmp(chosen_map, "CEILING", 4))
		return "C";
	return 0;
}
