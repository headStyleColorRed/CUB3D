/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:56:14 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/17 17:04:59 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	initialize_map_variables_1(t_game *game)
{
	game->window.width = game->map->resolution.width;
	game->window.height = game->map->resolution.height;
	game->raycast.pos_x = game->raycast.player_position.x_grid;
	game->raycast.pos_y = game->raycast.player_position.y_grid;
	game->raycast.dir_x = -1.0;
	game->raycast.dir_y = 0;
	game->raycast.plane_x = 0;
	game->raycast.plane_y = 0.66;
	game->raycast.time = 0;
	game->raycast.old_time = 0;
	game->raycast.current_ray = 0;
	game->raycast.map_x = 0;
	game->raycast.map_y = 0;
	game->raycast.step_x = 0;
	game->raycast.step_y = 0;
	game->raycast.hit = 0;
	game->raycast.side = 0;
	game->raycast.line_height = 0;
}

void	initialize_map_variables_2(t_game *game)
{
	game->raycast.draw_start = 0;
	game->raycast.draw_end = 0;
	game->raycast.celing_color = 0x66CCFF;
	game->raycast.wall_color = 0x00FF00;
	game->raycast.floor_color = 0x333333;
	game->raycast.camera_x = 0;
	game->raycast.delta_dist_x = 0;
	game->raycast.delta_dist_y = 0;
	game->raycast.side_dist_x = 0;
	game->raycast.side_dist_y = 0;
	game->raycast.perp_wall_dist = 0;
	game->raycast.ray_dir_x = 0;
	game->raycast.ray_dir_y = 0;
	game->raycast.movement_speed = 0.05;
	game->raycast.rotation_speed = 0.05;
	game->raycast.move_up = 0;
	game->raycast.move_down = 0;
	game->raycast.move_right = 0;
	game->raycast.move_left = 0;
}

void	update_orientation(t_game *game, double dir_x, double dir_y, double plane_x, double plane_y)
{
	game->raycast.dir_x = dir_x;
	game->raycast.dir_y = dir_y;
	game->raycast.plane_x = plane_x;
	game->raycast.plane_y = plane_y;
}

void	player_orientation(t_game *game)
{
	char orientation;
	
	orientation = game->raycast.player_position.orientation;
	if (orientation == 'W')
		update_orientation(game, -1, 0, 0, 0.66);
	if (orientation == 'E')
		update_orientation(game, 1, 0, 0, -0.66);
	if (orientation == 'S')
		update_orientation(game, 0, -1, -0.66, 0);
	if (orientation == 'N')
		update_orientation(game, 0, 1, 0.66, 0);
}