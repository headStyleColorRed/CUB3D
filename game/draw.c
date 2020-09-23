/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/23 13:03:14 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

/*
**	put_pxl_to_img, 0()
**	After checking that the ray isn't offlimits, we copy the chosen color to
**	the image array by jumping from ray to ray to the next line.
*/

void	put_pxl_to_img(t_game *game, int i, int color, int is_wall)
{

	if (game->raycast.current_ray >= game->window.width && i >= game->window.height)
		return ;

	if (game->raycast.textures_on && is_wall)
	{
		game->raycast.text_y = abs((((i * 256 - game->window.height * 128 + game->raycast.line_height * 128) * 64) / game->raycast.line_height) / 256);

		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &game->raycast.textures[game->raycast.text_orient].data[game->raycast.text_y % 64 * game->raycast.textures[game->raycast.text_orient].sizeline + game->raycast.text_x % 64 * game->raycast.textures[game->raycast.text_orient].bpp / 8], sizeof(int));
	}
	else
	{
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &color, sizeof(int));
	}
}


void get_orientation_ray(t_game *game)
{
	if (game->raycast.side == 0)
	{
		if (game->raycast.ray_dir_x <= 0)
			game->raycast.text_orient = 0;
		else
			game->raycast.text_orient = 1;
	}
	else
	{
		if (game->raycast.ray_dir_y <= 0)
			game->raycast.text_orient = 2;
		else
			game->raycast.text_orient = 3;
	}
	if (game->map.map_matrix[game->raycast.map_x][game->raycast.map_y] == '2')
		game->raycast.text_orient = 4;

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
		if (game->raycast.side == 0)
			game->raycast.wall_x = game->raycast.pos_y + game->raycast.perp_wall_dist * game->raycast.ray_dir_y;
		else
			game->raycast.wall_x = game->raycast.pos_x + game->raycast.perp_wall_dist * game->raycast.ray_dir_x;

		get_orientation_ray(game);

		game->raycast.text_x = (int)(game->raycast.wall_x * (double)64);

		if (game->raycast.side == 0 && game->raycast.ray_dir_x > 0)
			game->raycast.text_x = 64 - game->raycast.text_x - 1;
		if (game->raycast.side == 1 && game->raycast.ray_dir_y < 0)
			game->raycast.text_x = 64 - game->raycast.text_x - 1;

		game->raycast.text_x = abs(game->raycast.text_x);

	}
	while (i <= game->raycast.draw_end)
	{
		put_pxl_to_img(game, i, game->raycast.wall_color, 1);
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
		put_pxl_to_img(game, i++, game->raycast.celing_color, 0);

	i = game->raycast.draw_end;
	if (game->raycast.draw_end > 0)
		while (i < game->window.height)
			put_pxl_to_img(game, i++, game->raycast.floor_color, 0);
}

void	load_textures(t_game *game)
{
	int a;
	int b;

	a = 64;
	b = 64;
	game->raycast.textures[TEXT_NORTH].img = mlx_xpm_file_to_image(game->window.mlx, game->map.map_textures.NO_texture, &a, &b);
	game->raycast.textures[TEXT_NORTH].data = mlx_get_data_addr(game->raycast.textures[TEXT_NORTH].img,
																&game->raycast.textures[TEXT_NORTH].bpp,
																&game->raycast.textures[TEXT_NORTH].sizeline,
																&game->raycast.textures[TEXT_NORTH].endian);

	game->raycast.textures[TEXT_SOUTH].img = mlx_xpm_file_to_image(game->window.mlx, game->map.map_textures.SO_texture, &a, &b);
	game->raycast.textures[TEXT_SOUTH].data = mlx_get_data_addr(game->raycast.textures[TEXT_SOUTH].img,
																&game->raycast.textures[TEXT_SOUTH].bpp,
																&game->raycast.textures[TEXT_SOUTH].sizeline,
																&game->raycast.textures[TEXT_SOUTH].endian);


	game->raycast.textures[TEXT_WEST].img = mlx_xpm_file_to_image(game->window.mlx, game->map.map_textures.WE_texture, &a, &b);
	game->raycast.textures[TEXT_WEST].data = mlx_get_data_addr(game->raycast.textures[TEXT_WEST].img,
																&game->raycast.textures[TEXT_WEST].bpp,
																&game->raycast.textures[TEXT_WEST].sizeline,
																&game->raycast.textures[TEXT_WEST].endian);


	game->raycast.textures[TEXT_EAST].img = mlx_xpm_file_to_image(game->window.mlx, game->map.map_textures.EA_texture, &a, &b);
	game->raycast.textures[TEXT_EAST].data = mlx_get_data_addr(game->raycast.textures[TEXT_EAST].img,
																&game->raycast.textures[TEXT_EAST].bpp,
																&game->raycast.textures[TEXT_EAST].sizeline,
																&game->raycast.textures[TEXT_EAST].endian);


	game->raycast.textures[TEXT_SPRITE].img = mlx_xpm_file_to_image(game->window.mlx, game->map.map_textures.SP_texture, &a, &b);
	game->raycast.textures[TEXT_SPRITE].data = mlx_get_data_addr(game->raycast.textures[TEXT_SPRITE].img,
																&game->raycast.textures[TEXT_SPRITE].bpp,
																&game->raycast.textures[TEXT_SPRITE].sizeline,
																&game->raycast.textures[TEXT_SPRITE].endian);
}
