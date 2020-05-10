//
//  main.c
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include <stdio.h>
#include "library.h"

int main(int argc, char **argv)
{
	char *raw_map;
	t_map map;
	
	raw_map = read_map();
	parse_cube_map(raw_map, &map);
	
	
	printf("%d\n", map.resolution.length);
	printf("%d\n", map.resolution.width);
	printf("%s\n", map.NO_texture);
	printf("%s\n", map.SO_texture);
	printf("%s\n", map.EA_texture);
	printf("%s\n", map.WE_texture);
	printf("%s\n", map.SP_texture);
	printf("floor:\n");
	printf("%d\n", map.floor_color.r_color);
	printf("%d\n", map.floor_color.g_color);
	printf("%d\n", map.floor_color.b_color);
	printf("ceiling:\n");
	printf("%d\n", map.ceiling_color.r_color);
	printf("%d\n", map.ceiling_color.g_color);
	printf("%d\n", map.ceiling_color.b_color);
	

	
	return (0);
}
