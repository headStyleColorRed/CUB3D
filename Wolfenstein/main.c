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
	int i;
	
	i = 0;
	if (argc == 1)
		process_file("map0.cub");
	if (argc == 2)
		process_file(argv[argc - 1]);
	else {
		while (i++ < argc - 1)
			process_file(argv[i]);
	}
	
	

	return (0);
}
