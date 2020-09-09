#include <stdio.h>
#include "library.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	file_processor(argc, argv, &map);
	game.map = &map;
	start_game(&game);
	
	printf("\nTodo ok!\n");
	return (0);
}
