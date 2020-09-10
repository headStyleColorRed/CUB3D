/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/09 22:07:31 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	put_pxl_to_img(t_game *game)
{
	if (game->raycast.current_ray < game->window.width && game->raycast.draw_start < game->window.width)
		ft_memcpy(game->window.img_ptr + 4 * game->window.width * game->raycast.draw_start * game->raycast.current_ray, &game->raycast.wall_color, sizeof(int));
}

void draw_wall(t_game *game)
{
	
	while (game->raycast.draw_start <= game->raycast.draw_end)
	{
		put_pxl_to_img(game);
		game->raycast.draw_start++;
	}
}


void draw_floor_and_ceiling(t_game *game)
{
	(void)game;
}