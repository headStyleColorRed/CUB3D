/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:52:11 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/08 00:08:50 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void init_raycast(t_game *game)
{
	t_raycasting raycast;

	raycast = game->raycast;

	raycast.camera = 2 * game->raycast.current_ray / (double)(game->window.width) - 1;
	raycast.ray_dir_x = raycast.init_ray_dir_x + raycast.plane_x * raycast.camera;
	raycast.ray_dir_y = raycast.init_ray_dir_y + raycast.plane_y * raycast.camera;

	game->raycast.delta_dist_x = sqrt(1 + square_of(game->raycast.ray_dir_y) / square_of(game->raycast.ray_dir_x));
	game->raycast.delta_dist_y = sqrt(1 + square_of(game->raycast.ray_dir_x) / square_of(game->raycast.ray_dir_y));
}

void int_dda(t_game *game)
{
	
}
