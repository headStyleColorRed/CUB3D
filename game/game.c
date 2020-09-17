/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:28:31 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/17 13:40:51 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void initialize_map_variables(t_game *game)
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

void    set_up_window(t_game *game)
{
    if (!(game->window.mlx = mlx_init()))
        print_error("Error initiating mlx");
    if (!(game->window.win = mlx_new_window(game->window.mlx, game->map->resolution.width, game->map->resolution.height, "Wolfenstein")))
        print_error("Error creating mlx window");
}

int    run_game(t_game *game)
{
	// new_frame(game);
	update_movement(game);
    
    return (0);
}


void    start_game(t_game *game)
{
    set_up_window(game);
    mlx_hook(game->window.win, X_EVENT_KEY_PRESS, 0, &pressed_key, game);
    mlx_hook(game->window.win, X_EVENT_KEY_RELEASE, 0, &released_key, game);

	set_player_begining_position(game);
	initialize_map_variables(game);
    
	mlx_loop_hook(game->window.mlx, &run_game, game);
	mlx_loop(game->window.mlx);
}
