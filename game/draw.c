/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:31:45 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 23:34:42 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	new_frame(t_game *game)
{
	mlx_destroy_image(game->window.ptr, game->window.img_ptr);
	game->window.img_ptr = mlx_new_image(game->window.ptr, game->window.width, game->window.height);
}