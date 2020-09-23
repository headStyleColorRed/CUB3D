/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:28:31 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/23 13:48:53 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

/*
**	A new window gets created using the mlx pointer,
**	a given resolution and chosen name.
*/

void	set_up_window(t_game *game)
{
	if (!(game->window.mlx = mlx_init()))
		print_error("Error initiating mlx");
	if (!(game->window.win = mlx_new_window(game->window.mlx, game->map.resolution.width, game->map.resolution.height, "Wolfenstein 3D")))
		print_error("Error creating mlx window");
}

/*
**	Game starts! Declarations are being made and hooks started.
*/

void	start_game(t_game *game)
{
	set_up_window(game);
	mlx_hook(game->window.win, X_EVENT_KEY_PRESS, 0, &pressed_key, game);
	mlx_hook(game->window.win, X_EVENT_KEY_RELEASE, 0, &released_key, game);
	set_player_begining_position(game);
	initialize_map_variables_1(game);
	initialize_map_variables_2(game);
	load_ceiling_floor_colors(game);

	load_textures(game);
	player_orientation(game);
	raycast(game);
	if (game->is_save)
		return ;
	mlx_loop_hook(game->window.mlx, &run_game, game);
	mlx_loop(game->window.mlx);
}
