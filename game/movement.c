/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:26:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/08 20:35:57 by rlabrado         ###   ########.fr       */
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
        
    return (0);
}

void    add_key_hooks(t_game *game)
{
    mlx_hook(game->window.win,X_EVENT_KEY_PRESS, 0, &pressed_key, game);
}

void update_movement(t_game *game)
{
	// TODO: Create the movement logic
	
	raycast(game);
}