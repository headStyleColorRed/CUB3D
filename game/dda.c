/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:52:11 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/09 21:29:11 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void dda_declarations(t_game *game)
{
	t_raycasting ray_cast;

	ray_cast = game->raycast;
	if (ray_cast.ray_dir_x < 0)
	{
		ray_cast.step_x = -1;
		ray_cast.side_dist_x = (ray_cast.pos_x - ray_cast.map_x) * ray_cast.delta_dist_x; 
	}
	else 
	{
		ray_cast.step_x = 1;
		ray_cast.side_dist_x = (ray_cast.map_x + 1.0 - ray_cast.pos_x)  * ray_cast.delta_dist_x;
	}
	if (ray_cast.ray_dir_y < 0)
	{
		ray_cast.step_y = -1;
		ray_cast.side_dist_y = (ray_cast.pos_y - ray_cast.map_y) * ray_cast.delta_dist_y; 
	}
	else
	{
		ray_cast.step_y = 1;
		ray_cast.side_dist_y= (ray_cast.map_y + 1.0 - ray_cast.pos_y)  * ray_cast.delta_dist_y;
	}
	
}


void execute_dda(t_game *game)
{
	t_raycasting ray_cast;

	ray_cast = game->raycast;
	while (ray_cast.hit == 0)
	{
		if (ray_cast.side_dist_x < ray_cast.side_dist_y)
		{
			ray_cast.side_dist_x += ray_cast.delta_dist_x;
			ray_cast.map_x += ray_cast.step_x;
			ray_cast.side = 0;
		} else
		{
			ray_cast.side_dist_y += ray_cast.delta_dist_y;
			ray_cast.map_y += ray_cast.step_y;
			ray_cast.side = 1;
		}	
		if (game->map->map_matrix[ray_cast.map_x][ray_cast.map_y] > 0)
			ray_cast.hit = 1;
	}
}