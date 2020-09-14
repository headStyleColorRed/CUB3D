/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:28:31 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/14 20:56:12 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void initialize_map_variables(t_game *game)
{
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
	game->raycast.wall_color = 0xdd8800;
	game->raycast.floor_color = 0x333333;
	game->raycast.camera_x = 0;
	game->raycast.delta_dist_x = 0;
	game->raycast.delta_dist_y = 0;
	game->raycast.side_dist_x = 0;
	game->raycast.side_dist_y = 0;
	game->raycast.perp_wall_dist = 0;
	game->raycast.ray_dir_x = 0;
	game->raycast.ray_dir_y = 0;
}

void    set_up_window(t_game *game)
{
	int			bpp;
	int			sizeline;
	int			endian;

    if (!(game->window.ptr = mlx_init()))
        print_error("Error initiating mlx");
    if (!(game->window.win = mlx_new_window(game->window.ptr, game->map->resolution.width, game->map->resolution.height, "Wolfenstein")))
        print_error("Error creating mlx window");
    if (!(game->window.img_ptr = mlx_new_image(game->window.ptr, game->map->resolution.width, game->map->resolution.height)))
        print_error("Error creating mlx new image");
    if (!(game->window.img_str = mlx_get_data_addr(game->window.img_ptr, &bpp, &sizeline, &endian)))
        print_error("Error creating mlx data address");
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
    add_key_hooks(game);

	set_player_begining_position(game);
	initialize_map_variables(game);
    
	mlx_loop_hook(game->window.ptr, &run_game, game);
	mlx_loop(game->window.ptr);
}
