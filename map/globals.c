//
//  globals.c
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

char	*map_textures(t_map_parser chosenMap)
{
	if(chosenMap == NORTH)
		return "NO";
	else if (chosenMap == SOUTH)
		return "SO";
	else if (chosenMap == WEST)
		return "WE";
	else if (chosenMap == EAST)
		return "EA";
	else if (chosenMap == RESOLUTION)
		return "R ";
	else if (chosenMap == SPRITE)
		return "S ";
	else if (chosenMap == FLOOR)
		return "F ";
	else if (chosenMap == CEILING)
		return "C ";
	return 0;
}
