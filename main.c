#include <stdio.h>
#include "library.h"

void	fill_my_matrix(void);
int	main(int argc, char **argv)
{
	// t_map	map;
	// t_game	game;

	(void)argc;
	(void)argv;
	// file_processor(argc, argv, &map);
	// start_game(&map, &game);
	
	printf("Todo ok!\n");
	return (0);
}


void	fill_my_matrix(void)
{	
	int matrix[5][5];
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++) {
			printf("[%d][%d]\n", i, j);
			(void)matrix;
		}
	}
}