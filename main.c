#include <stdio.h>
#include "library.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	file_processor(argc, argv, &map);
	start_game(&map, &game);
	
	printf("Todo ok!\n");
	return (0);
}
