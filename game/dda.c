/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:52:11 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/19 13:14:31 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

/*
**	dda_declarations()
**	Dda is the Digital Differential Analysis, which means, a calculator for the next colision grid.
**	Diferent conditionals depending on the direction of the ray left/right first and up/down and by
**	substracting the current position to the map position and multiplying to the next
**	colision zone, calculate the euclidean distance.
*/

void dda_declarations(t_game *game)
{
	if (game->raycast.ray_dir_x < 0)
	{
		game->raycast.step_x = -1;
		game->raycast.side_dist_x = (game->raycast.pos_x - game->raycast.map_x) * game->raycast.delta_dist_x; 
	}
	else 
	{
		game->raycast.step_x = 1;
		game->raycast.side_dist_x = (game->raycast.map_x + 1.0 - game->raycast.pos_x)  * game->raycast.delta_dist_x;
	}
	if (game->raycast.ray_dir_y < 0)
	{
		game->raycast.step_y = -1;
		game->raycast.side_dist_y = (game->raycast.pos_y - game->raycast.map_y) * game->raycast.delta_dist_y; 
	}
	else
	{
		game->raycast.step_y = 1;
		game->raycast.side_dist_y= (game->raycast.map_y + 1.0 - game->raycast.pos_y)  * game->raycast.delta_dist_y;
	}
	
}

/*
**	execute_dda()
** 	Once the dda calculations are done the next step is run square by square if a wall is hit.
**	Checking if the right or left grid is closest we add the delta distance and continue
**	adding it until a hit square (a 1 / 2) is found by the last conditional on the function.
*/

void execute_dda(t_game *game)
{
	while (game->raycast.hit == 0)
	{
		if (game->raycast.side_dist_x < game->raycast.side_dist_y)
		{
			game->raycast.side_dist_x += game->raycast.delta_dist_x;
			game->raycast.map_x += game->raycast.step_x;
			game->raycast.side = 0;
		} else
		{
			game->raycast.side_dist_y += game->raycast.delta_dist_y;
			game->raycast.map_y += game->raycast.step_y;
			game->raycast.side = 1;
		}	
		if (game->map->map_matrix[game->raycast.map_x][game->raycast.map_y] > 48)
			game->raycast.hit = 1;
	}
}