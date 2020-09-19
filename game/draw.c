/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/19 13:56:11 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	put_pxl_to_img(t_game *game, int i)
{
	if (game->raycast.current_ray < game->window.width && i < game->window.width)
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &game->raycast.wall_color, sizeof(int));
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
		put_pxl_to_img(game, i);
		i++;
	}
}

/*
**	draw_floor_and_ceiling()
**	We copy the colored pixels from the wall's start point, to the end one.
**	
**	
**	
**	
*/

void draw_floor_and_ceiling(t_game *game)
{
	int i;

	i = 0;
	if (game->raycast.current_ray < game->window.width)
	{
		while (i < game->raycast.draw_start)
		{
			ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &game->raycast.celing_color, sizeof(int));
			i++;
		}
	}
	
	if (game->raycast.draw_end > 0)
	{
		i = game->raycast.draw_end;
		if (game->raycast.current_ray < game->window.width && i < game->window.height)
		{
			while (i < game->window.height)
			{
				ft_memcpy(game->window.img_ptr + 4 * game->window.width * i + game->raycast.current_ray * 4, &game->raycast.floor_color, sizeof(int));
				i++;
			}

		}
	}
}