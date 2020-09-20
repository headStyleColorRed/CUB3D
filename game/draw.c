/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/20 16:28:26 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

/*
**	put_pxl_to_img()
**	After checking that the ray isn't offlimits, we copy the chosen color to
**	the image array by jumping from ray to ray to the next line.
*/

void	put_pxl_to_img(t_game *game, int i, int color)
{
	int y_text_pix;
	int	new_color;
	
	if (game->raycast.current_ray >= game->window.width && i >= game->window.height)
		return ;

	if (game->raycast.textures_on) 
	{
		y_text_pix = i * 256 - game->window.height * 128 + game->raycast.perp_wall_dist * 128;
		game->raycast.text_y = abs((int)((y_text_pix * 64) / game->raycast.perp_wall_dist) / 256);

		
		new_color = game->raycast.textures[game->raycast.id].data[game->raycast.text_y % 64 * game->raycast.textures[game->raycast.id].sizeline + game->raycast.text_x % 64 * game->raycast.textures[game->raycast.id].bpp / 8];
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &new_color, sizeof(int));
	} 
	else 
	{
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &color, sizeof(int));
	}
}

/*
**	draw_wall()
**	We copy the colored pixels from the wall's start point, to the end one.
*/

void draw_wall(t_game *game)
{
	int i;

	i = game->raycast.draw_start;
	if (game->raycast.textures_on)
	{
		game->raycast.id = game->map->map_matrix[game->raycast.map_x][game->raycast.map_y] - 48;
		if (game->raycast.side == 0)
			game->raycast.wall_x = game->raycast.pos_y + game->raycast.perp_wall_dist * game->raycast.ray_dir_y;
		else 
			game->raycast.wall_x = game->raycast.pos_x + game->raycast.perp_wall_dist * game->raycast.ray_dir_x;

		game->raycast.text_x = (int)(game->raycast.wall_x * (double)64);

		if (game->raycast.side == 0 && game->raycast.ray_dir_x > 0)
			game->raycast.text_x = 64 - game->raycast.text_x - 1;
		if (game->raycast.side == 1 && game->raycast.ray_dir_y < 0)
			game->raycast.text_x = 64 - game->raycast.text_x - 1;
		
		game->raycast.text_x = abs(game->raycast.text_x);

	}
	while (i <= game->raycast.draw_end)
	{
		put_pxl_to_img(game, i, game->raycast.wall_color);
		i++;
	}
}

/*
**	draw_floor_and_ceiling()
**	We copy the colored pixels from the screen first pixel to the wall's start point.
**	and from the wall's end pixel to the screen's end pixel.
*/

void draw_floor_and_ceiling(t_game *game)
{
	int i;

	i = 0;
	while (i < game->raycast.draw_start)
		put_pxl_to_img(game, i++, game->raycast.celing_color);
	i = game->raycast.draw_end;
	if (game->raycast.draw_end > 0)
		while (i < game->window.height)
			put_pxl_to_img(game, i++, game->raycast.floor_color);
}

void	load_textures(t_game *game)
{
	int a;
	int b;

	a = 64;
	b = 64;
	game->raycast.textures[TEX_CEILING].img = mlx_xpm_file_to_image(game->window.mlx, "textures/sky.xpm", &a, &b);
	game->raycast.textures[TEX_CEILING].data = mlx_get_data_addr(game->raycast.textures[TEX_CEILING].img, &game->raycast.textures[TEX_CEILING].bpp, &game->raycast.textures[TEX_CEILING].sizeline, &game->raycast.textures[TEX_CEILING].endian);

	game->raycast.textures[TEX_WALL].img = mlx_xpm_file_to_image(game->window.mlx, "textures/stone.xpm", &a, &b);
	game->raycast.textures[TEX_WALL].data = mlx_get_data_addr(game->raycast.textures[TEX_WALL].img, &game->raycast.textures[TEX_WALL].bpp, &game->raycast.textures[TEX_WALL].sizeline, &game->raycast.textures[TEX_WALL].endian);

	game->raycast.textures[TEX_FLOOR].img = mlx_xpm_file_to_image(game->window.mlx, "textures/sand.xpm", &a, &b);
	game->raycast.textures[TEX_FLOOR].data = mlx_get_data_addr(game->raycast.textures[TEX_FLOOR].img, &game->raycast.textures[TEX_FLOOR].bpp, &game->raycast.textures[TEX_FLOOR].sizeline, &game->raycast.textures[TEX_FLOOR].endian);
}
