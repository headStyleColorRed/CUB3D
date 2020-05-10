//
//  map_manager.c
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

char *read_map(void)
{
	int fd;
	int i;
	char buffer;
	char *map;

	int ft;
	ft = open("map0.cub", O_RDONLY);
	if (ft == -1)
	{
		print_error("Not found .cub file");
	}

	map = (char *)ft_calloc(4065, 1);
	if (!map)
		print_error("Allocation error");
	i = 0;
	while ((fd = read(ft, &buffer, 1)))
		map[i++] = buffer;
	close(fd);
	return (map);
}
