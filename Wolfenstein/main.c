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
	t_map map;
	t_window	window;
	
	file_processor(argc, argv, &map);
	start_game(&map, &window);

	printf("Todo ok!\n");
	return (0);
}