//
//  globals.h
//  Wolfenstein
//
//  Created by Rodrigo  on 10/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#ifndef globals_h
#define globals_h

typedef enum e_map_parser
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	RESOLUTION,
	SPRITE,
	FLOOR,
	CEILING,
	MAP
}			t_map_parser;

typedef enum e_bool
{
	ft_false,
	ft_true
}			t_bool;

char	*map_textures(t_map_parser chosenMap);
#endif 
