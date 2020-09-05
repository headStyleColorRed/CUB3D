/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converting_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:14:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/05 12:28:15 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

void print_matrix(char **matrix, int height, int width)
{
	int i = 0;
	int j = 0;

	while (i < height) {
		j = 0;
		while (j < width) {
			printf("%c ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

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
	print_matrix(map->map_matrix, map->map_height, map->map_width);
}
