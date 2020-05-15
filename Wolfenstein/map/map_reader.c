//
//  map_manager.c
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

char *read_map(t_map *raw_map)
{
	int fd;
	int i;
	char buffer;
	char *map;

	int ft;
	ft = open(raw_map->map_file , O_RDONLY);
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

void	process_file(char *map_file, t_map *map)
{
	char *raw_map;
	
	map->map_file = map_file;
	
	raw_map = read_map(map);
	
	parse_cube_map(raw_map, map);
	check_file_conformity(map);
}

void	file_processor(int argc, char **argv, t_map *map)
{
	int i;
	
	i = 0;
	if (argc == 1)
		process_file("map2.cub", map);
	if (argc == 2)
		process_file(argv[argc - 1], map);
	else {
		while (i++ < argc - 1)
			process_file(argv[i], map);
	}
}
