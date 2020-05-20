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