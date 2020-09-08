/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:30 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/08 21:47:57 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void wall_calculation(t_game *game)
{
	t_raycasting ray_cast;

	ray_cast = game->raycast;
	if (ray_cast.side == 0)
		ray_cast.perp_wall_dist = (ray_cast.map_x - ray_cast.pos_x + (1 - ray_cast.step_x) / 2) / ray_cast.ray_dir_x;
	else 
		ray_cast.perp_wall_dist = (ray_cast.map_y - ray_cast.pos_y + (1 - ray_cast.step_y) / 2) / ray_cast.ray_dir_y;

	ray_cast.line_height = (int)(game->window.height / ray_cast.perp_wall_dist);
	ray_cast.draw_start = -ray_cast.line_height / 2 + game->window.height - 1;
	if (ray_cast.draw_start < 0)
		ray_cast.draw_start = 0;
	ray_cast.draw_end = ray_cast.line_height / 2 + game->window.height / 2;
	if (ray_cast.draw_end >= game->window.height)
		ray_cast.draw_end = game->window.height - 1;
}

void raycast_declarations(t_game *game)
{
	t_raycasting ray_cast;

	ray_cast = game->raycast;
	ray_cast.camera_x = 2 * ray_cast.current_ray / (double)game->window.width - 1;
	ray_cast.ray_dir_x = ray_cast.dir_x + ray_cast.plane_x * ray_cast.camera_x;
	ray_cast.ray_dir_y = ray_cast.dir_y + ray_cast.plane_y * ray_cast.camera_x;
	ray_cast.map_x = (int)ray_cast.pos_x;
	ray_cast.map_y = (int)ray_cast.pos_y;
	ray_cast.delta_dist_x = abs(1 / ray_cast.ray_dir_x);
	ray_cast.delta_dist_y = abs(1 / ray_cast.ray_dir_y);
	ray_cast.hit = 0;

}

void raycast(t_game *game)
{
	t_raycasting ray_cast;
	
	ray_cast = game->raycast;
	while(ray_cast.current_ray < game->window.width)
	{
		raycast_declarations(game);
		dda_declarations(game);
		execute_dda(game);
		wall_calculation(game)



		ray_cast.current_ray++;
	}
}