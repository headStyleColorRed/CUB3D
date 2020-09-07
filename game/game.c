/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:28:31 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 23:44:50 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void initialize_map_variables(t_game *game)
{
	game->raycast.current_ray = 0;
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
    if (!(game->window.img_str = mlx_get_data_addr(game->window.img_ptr, bpp, sizeline, endian)))
        print_error("Error creating mlx data address");
}

int    run_game(t_game *game)
{
	new_frame(game);
	update_movement(game);
    
    return (0);
}


void    start_game(t_map *map, t_game *game)
{
    set_up_window(game);
	game->map = map; // El orden es importante. key_hooks debajo siempre!
    add_key_hooks(game);

	set_player_begining_position(game);
	initialize_map_variables(game);
    
	mlx_loop_hook(game->window.ptr, &run_game, game);
	mlx_loop(game->window.ptr);
}
