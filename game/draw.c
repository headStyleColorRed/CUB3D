/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 23:55:54 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	new_frame(t_game *game)
{
	mlx_destroy_image(game->window.ptr, game->window.img_ptr);
	game->window.img_ptr = mlx_new_image(game->window.ptr, game->window.width, game->window.height);
}


// y_raydir: camera_plane.y
// x_cam: camera_plane.x

/*
* Ray casting Init:
*	1. camera_plane: Camera plane.
*	2. ray_direction x/y: el vector de dirección del rayo
*/

void	draw_map(t_game *game)
{
	game->raycast.current_ray = -1;
	while (++game->raycast.current_ray < game->window.width)
	{
		init_raycast(game);
		int_dda(game);
	}
}