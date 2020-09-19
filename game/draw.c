/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/19 14:21:18 by rlabrado         ###   ########.fr       */
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
	if (game->raycast.current_ray < game->window.width && i < game->window.width)
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &color, sizeof(int));
}

/*
**	draw_wall()
**	We copy the colored pixels from the wall's start point, to the end one.
*/

void draw_wall(t_game *game)
{
	int i;

	i = game->raycast.draw_start;
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