/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:26:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/15 18:06:40 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

int     pressed_key(int keycode, t_game *game)
{   
    if (keycode == KEY_W ||
        keycode == KEY_S ||
        keycode == KEY_D ||
        keycode == KEY_A )
        check_for_movement(game, keycode);
	else if(keycode == KEY_ESC)
		exit(1);
        
    return (0);
}

void update_movement(t_game *game)
{
	if (game->movement == UP)
	{
		if (game->map->map_matrix[(int)(game->raycast.pos_x + game->raycast.dir_x * game->raycast.movement_speed)][(int)game->raycast.pos_y] != '1')
			game->raycast.pos_x += game->raycast.dir_x * game->raycast.movement_speed;
		if (game->map->map_matrix[(int)game->raycast.pos_x][(int)(game->raycast.pos_y + game->raycast.dir_y * game->raycast.movement_speed)] != '1')
			game->raycast.pos_y += game->raycast.dir_y * game->raycast.movement_speed;
	}

	if (game->movement == DOWN)
	{
		if (game->map->map_matrix[(int)(game->raycast.pos_x - game->raycast.dir_x * game->raycast.movement_speed)][(int)game->raycast.pos_y] != '1')
			game->raycast.pos_x -= game->raycast.dir_x * game->raycast.movement_speed;
		if (game->map->map_matrix[(int)game->raycast.pos_x][(int)(game->raycast.pos_y - game->raycast.dir_y * game->raycast.movement_speed)] != '1')
			game->raycast.pos_y -= game->raycast.dir_y * game->raycast.movement_speed;
	}









	game->movement = NONE;
	raycast(game);
}