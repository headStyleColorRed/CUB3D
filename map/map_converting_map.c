/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converting_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:14:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/23 14:33:37 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void	transform_file_to_matrix(t_map *map)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	map->map_matrix = malloc(map->map_height * sizeof(char *));
	while (i < map->map_height)
		map->map_matrix[i++] = malloc(map->map_width * sizeof(char));
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == '\n')
		{
			k++;
			j = 0;
		}
		else
			map->map_matrix[k][j++] = map->map[i];
		i++;
	}
}

char	*map_textures(t_map_parser chosenMap)
{

	if(chosenMap == NORTH)
		return "NO";
	else if (chosenMap == SOUTH)
		return "SO";
	else if (chosenMap == WEST)
		return "WE";
	else if (chosenMap == EAST)
		return "EA";
	else if (chosenMap == RESOLUTION)
		return "R ";
	else if (chosenMap == SPRITE)
		return "S ";
	else if (chosenMap == FLOOR)
		return "F ";
	else if (chosenMap == CEILING)
		return "C ";
	return 0;
}
