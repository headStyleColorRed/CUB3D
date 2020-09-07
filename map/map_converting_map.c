/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converting_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:14:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 22:14:14 by rlabrado         ###   ########.fr       */
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
		{
			if (ft_isalnum(map->map[i]) == 1)
				map->map_matrix[k][j++] = ft_atoi(&map->map[i]);
			else
				map->map_matrix[k][j++] = 8;
		}
		i++;
	}
}
