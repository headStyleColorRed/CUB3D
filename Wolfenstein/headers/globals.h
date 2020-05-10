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
	CEILING
}			t_map_parser;

char	*map_textures(t_map_parser chosenMap);
#endif 
