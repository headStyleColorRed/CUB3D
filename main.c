#include <stdio.h>
#include "library.h"

int	main(int argc, char **argv)
{
	t_game	game;

	file_processor(argc, argv, &game);
	// start_game(&game);

	printf("\nTodo ok!\n");
	return (0);
}
