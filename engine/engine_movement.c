#include "../library.h"

void check_for_movement(t_game *game, int keycode)
{
	int speed;

	speed = 5;
	if (keycode == KEY_W)
		game->player_position.y -= speed;
	else if (keycode == KEY_S)
		game->player_position.y += speed;
	else if (keycode == KEY_D)
		game->player_position.x += speed;
	else if (keycode == KEY_A)
		game->player_position.x -= speed;
}

// void	set_player_begining_position(t_game *game)
// {
// 	(void)game;
// 	char **matrix;
// 	int i = 0;
// 	int j = 0;

// 	matrix = game->map->map_matrix;
// 	while (i < game->map->map_height) {
// 		j = 0;
// 		while (j < game->map->map_width) {
// 			if (ft_check_if_character(matrix[i][j], "NSWE")) {
// 				game->player_position.x_grid = j;
// 				game->player_position.y_grid = i;
// 				game->player_position.x = (j * SQUARE_SIZE) + (SQUARE_SIZE / 2);
// 				game->player_position.y = (i * SQUARE_SIZE) + (SQUARE_SIZE / 2);
// 				return;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}


// }