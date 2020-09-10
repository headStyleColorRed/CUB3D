/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:30 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/09 22:07:29 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void wall_calculation(t_game *game)
{
	if (game->raycast.side == 0)
		game->raycast.perp_wall_dist = (game->raycast.map_x - game->raycast.pos_x + (1 - game->raycast.step_x) / 2) / game->raycast.ray_dir_x;
	else 
		game->raycast.perp_wall_dist = (game->raycast.map_y - game->raycast.pos_y + (1 - game->raycast.step_y) / 2) / game->raycast.ray_dir_y;

	game->raycast.line_height = (int)(game->window.height / game->raycast.perp_wall_dist);
	game->raycast.draw_start = -game->raycast.line_height / 2 + game->window.height - 1;
	if (game->raycast.draw_start < 0)
		game->raycast.draw_start = 0;
	game->raycast.draw_end = game->raycast.line_height / 2 + game->window.height / 2;
	if (game->raycast.draw_end >= game->window.height)
		game->raycast.draw_end = game->window.height - 1;
}

void raycast_declarations(t_game *game)
{
	game->raycast.camera_x = 2 * game->raycast.current_ray / (double)game->window.width - 1;
	game->raycast.ray_dir_x = game->raycast.dir_x + game->raycast.plane_x * game->raycast.camera_x;
	game->raycast.ray_dir_y = game->raycast.dir_y + game->raycast.plane_y * game->raycast.camera_x;
	game->raycast.map_x = (int)game->raycast.pos_x;
	game->raycast.map_y = (int)game->raycast.pos_y;
	game->raycast.delta_dist_x = fabs(1 / game->raycast.ray_dir_x);
	game->raycast.delta_dist_y = fabs(1 / game->raycast.ray_dir_y);
	game->raycast.hit = 0;

}

void raycast(t_game *game)
{
	while(game->raycast.current_ray < game->window.width)
	{
		raycast_declarations(game);
		dda_declarations(game);
		execute_dda(game);
		wall_calculation(game);

		draw_wall(game);
		draw_floor_and_ceiling(game);


		game->raycast.current_ray++;
	}
}