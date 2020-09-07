/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:31:07 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 22:33:10 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../library.h"

void dda_init(t_game *game)
{
	game->raycast.x_deltadist = sqrt(1 + (game->raycast.y_raydir * game->raycast.y_raydir) / (game->raycast.x_raydir * game->raycast.x_raydir));
	game->raycast.y_deltadist = sqrt(1 + (game->raycast.x_raydir * game->raycast.x_raydir) / (game->raycast.y_raydir * game->raycast.y_raydir));
	
	if (game->raycast.x_raydir < 0)
	{
		game->raycast.x_step = -1;
		game->raycast.x_sidedist = (game->raycast.x_raypos - game->raycast.x_map) * game->raycast.x_deltadist;
	}
	else
	{
		game->raycast.x_step = 1;
		game->raycast.x_sidedist = (game->raycast.x_map + 1.0 - game->raycast.x_raypos) * game->raycast.x_deltadist;
	}
	if (game->raycast.y_raydir < 0)
	{
		game->raycast.y_step = -1;
		game->raycast.y_sidedist = (game->raycast.y_raypos - game->raycast.y_map) * game->raycast.y_deltadist;
	}
	else
	{
		game->raycast.y_step = 1;
		game->raycast.y_sidedist = (game->raycast.y_map + 1.0 - game->raycast.y_raypos) * game->raycast.y_deltadist;
	}
}

void dda(t_game *game)
{
	game->raycast.hit = 0;
	while (game->raycast.hit == 0)
	{
		if (game->raycast.x_sidedist < game->raycast.y_sidedist)
		{
			game->raycast.x_sidedist += game->raycast.x_deltadist;
			game->raycast.x_map += game->raycast.x_step;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.y_sidedist += game->raycast.y_deltadist;
			game->raycast.y_map += game->raycast.y_step;
			game->raycast.side = 1;
		}
		if (game->raycast.map[game->raycast.x_map][game->raycast.y_map] > 0)
			game->raycast.hit = 1;
	}
}

void	put_pxl_to_img(t_game *game, int x, int y, int color)
{
	if (x < WINX && y < WINY)
		ft_memcpy(game->raycast.img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_game *game)
{
	if (game->raycast.texture == 1)
	{
		game->raycast.id = game->raycast.map[game->raycast.x_map][game->raycast.y_map];
		if (game->raycast.side == 0)
			game->raycast.x_wall = game->raycast.y_raypos + game->raycast.walldist * game->raycast.y_raydir;
		else
			game->raycast.x_wall = game->raycast.x_raypos + game->raycast.walldist * game->raycast.x_raydir;
		game->raycast.x_text = (int)(game->raycast.x_wall * (double)(64));
		if (game->raycast.side == 0 && game->raycast.x_raydir > 0)
			game->raycast.x_text = 64 - game->raycast.x_text - 1;
		if (game->raycast.side == 1 && game->raycast.y_raydir < 0)
			game->raycast.x_text = 64 - game->raycast.x_text - 1;
		game->raycast.x_text = abs(game->raycast.x_text);
	}
	while (++start <= end)
		put_pxl_to_img(game, x, start, game->raycast.color);
}

void floor_and_ceiling(t_game *game, int x)
{
	if (game->raycast.texture == 0)
	{
		if (game->raycast.start > 0)
		{
			game->raycast.color = 0x66CCFF;
			game->raycast.y = -1;
			if (x < WINX && game->raycast.y < WINY)
				while (++game->raycast.y < game->raycast.start)
				{
					ft_memcpy(game->raycast.img_ptr + 4 * WINX * game->raycast.y + x * 4,
							  &game->raycast.color, sizeof(int));
				}
		}
	}
	if (game->raycast.end > 0)
	{
		game->raycast.color = 0x333333;
		game->raycast.y = game->raycast.end - 1;
		if (x < WINX && game->raycast.y < WINY)
			while (++game->raycast.y < WINY)
				ft_memcpy(game->raycast.img_ptr + 4 * WINX * game->raycast.y + x * 4,
						  &game->raycast.color, sizeof(int));
	}
}

void wolf3d_init(t_game *game)
{
	game->raycast.x_pos = 3;
	game->raycast.y_pos = 3;
	game->raycast.x_dir = -1;
	game->raycast.y_dir = 0;
	game->raycast.x_plane = 0;
	game->raycast.y_plane = 0.66;
	game->raycast.ms = 0.05;
	game->raycast.rs = 0.05;
	game->raycast.move_up = 0;
	game->raycast.move_down = 0;
	game->raycast.move_left = 0;
	game->raycast.move_right = 0;
	game->raycast.x_text = 0;
	game->raycast.y_text = 0;
}

void ray_casting_init(t_game *game, int x)
{
	game->raycast.x_cam = 2 * x / (double)(WINX)-1;
	game->raycast.x_raypos = game->raycast.x_pos;
	game->raycast.y_raypos = game->raycast.y_pos;
	game->raycast.x_raydir = game->raycast.x_dir + game->raycast.x_plane * game->raycast.x_cam;
	game->raycast.y_raydir = game->raycast.y_dir + game->raycast.y_plane * game->raycast.x_cam;
	game->raycast.x_map = (int)game->raycast.x_raypos;
	game->raycast.y_map = (int)game->raycast.y_raypos;
	dda_init(game);
	dda(game);
	if (game->raycast.side == 0)
		game->raycast.walldist = (game->raycast.x_map - game->raycast.x_raypos +
								  (1 - game->raycast.x_step) / 2) /
								 game->raycast.x_raydir;
	else
		game->raycast.walldist = (game->raycast.y_map - game->raycast.y_raypos +
								  (1 - game->raycast.y_step) / 2) /
								 game->raycast.y_raydir;
}

void ray_casting(t_game *game)
{
	game->raycast.x = -1;
	game->raycast.img = mlx_new_image(game->window.ptr, WINX, WINY);
	game->raycast.img_ptr = mlx_get_data_addr(game->raycast.img, &game->raycast.bpp, &game->raycast.sl, &game->raycast.endian);
	while (++game->raycast.x < WINX)
	{
		ray_casting_init(game, game->raycast.x);
		game->raycast.lineheight = (int)(WINY / game->raycast.walldist);
		game->raycast.start = -game->raycast.lineheight / 2 + WINY / 2;
		if (game->raycast.start < 0)
			game->raycast.start = 0;
		game->raycast.end = game->raycast.lineheight / 2 + WINY / 2;
		if (game->raycast.end >= WINY)
			game->raycast.end = WINY - 1;
		if (game->raycast.side == 1)
			game->raycast.color = 0xdd8800;
		else
			game->raycast.color = 0x00FF00;
		draw_wall(game->raycast.x, game->raycast.start - 1, game->raycast.end, game);
		floor_and_ceiling(game, game->raycast.x);
	}
	mlx_put_image_to_window(game->window.ptr, game->window.win, game->raycast.img, 0, 0);
	mlx_destroy_image(game->window.ptr, game->raycast.img);
}

void	move_side(t_game *game)
{
	if (game->raycast.move_right == 1)
	{
		game->raycast.x_olddir = game->raycast.x_dir;
		game->raycast.x_dir = game->raycast.x_dir * cos(-game->raycast.rs) - game->raycast.y_dir * sin(-game->raycast.rs);
		game->raycast.y_dir = game->raycast.x_olddir * sin(-game->raycast.rs) + game->raycast.y_dir * cos(-game->raycast.rs);
		game->raycast.x_oldplane = game->raycast.x_plane;
		game->raycast.x_plane = game->raycast.x_plane * cos(-game->raycast.rs) - game->raycast.y_plane * sin(-game->raycast.rs);
		game->raycast.y_plane = game->raycast.x_oldplane * sin(-game->raycast.rs) + game->raycast.y_plane * cos(-game->raycast.rs);
	}
	if (game->raycast.move_left == 1)
	{
		game->raycast.x_olddir = game->raycast.x_dir;
		game->raycast.x_dir = game->raycast.x_dir * cos(game->raycast.rs) - game->raycast.y_dir * sin(game->raycast.rs);
		game->raycast.y_dir = game->raycast.x_olddir * sin(game->raycast.rs) + game->raycast.y_dir * cos(game->raycast.rs);
		game->raycast.x_oldplane = game->raycast.x_plane;
		game->raycast.x_plane = game->raycast.x_plane * cos(game->raycast.rs) - game->raycast.y_plane * sin(game->raycast.rs);
		game->raycast.y_plane = game->raycast.x_oldplane * sin(game->raycast.rs) + game->raycast.y_plane * cos(game->raycast.rs);
	}
}

int		move(t_game *game)
{
	if (game->raycast.move_up == 1)
	{
		if (game->raycast.map[(int)(game->raycast.x_pos + game->raycast.x_dir * game->raycast.ms)][(int)(game->raycast.y_pos)] == 0)
			game->raycast.x_pos += game->raycast.x_dir * game->raycast.ms;
		if (game->raycast.map[(int)(game->raycast.x_pos)][(int)(game->raycast.y_pos + game->raycast.y_dir * game->raycast.ms)] == 0)
			game->raycast.y_pos += game->raycast.y_dir * game->raycast.ms;
	}
	if (game->raycast.move_down == 1)
	{
		if (game->raycast.map[(int)(game->raycast.x_pos - game->raycast.x_dir * game->raycast.ms)][(int)(game->raycast.y_pos)] == 0)
			game->raycast.x_pos -= game->raycast.x_dir * game->raycast.ms;
		if (game->raycast.map[(int)(game->raycast.x_pos)][(int)(game->raycast.y_pos - game->raycast.y_dir * game->raycast.ms)] == 0)
			game->raycast.y_pos -= game->raycast.y_dir * game->raycast.ms;
	}
	move_side(game);
	ray_casting(game);
	return (0);
}







int     pressed_key(int keycode, t_game *game)
{   
    if (keycode == KEY_W ||
        keycode == KEY_S ||
        keycode == KEY_D ||
        keycode == KEY_A )
        check_for_movement(game, keycode);
        
    return (0);
}

void    add_key_hooks(t_game *game)
{
    mlx_hook(game->window.win,X_EVENT_KEY_PRESS, 0, &pressed_key, game);
}

void    set_up_window(t_map *map, t_window *window)
{
    if (!(window->ptr = mlx_init()))
        print_error("Error initiating mlx");
    if (!(window->win = mlx_new_window(window->ptr, map->resolution.width, map->resolution.height, "Wolfenstein")))
        print_error("Error creating mlx window");
}


void    start_game(t_map *map, t_game *game)
{

    set_up_window(map, &game->window);
	wolf3d_init(game);
	game->raycast.map = map->map_matrix;
    add_key_hooks(game);

	// set_player_begining_position(game);
    
	mlx_loop_hook(game->window.ptr, move, game);
	mlx_loop(game->window.ptr);
}
