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
	
	file_processor(argc, argv, &map);
	
	
	
	
	printf("Todo ok!\n");
	printf("%s\n\n", map.map);
	
	return (0);
}
