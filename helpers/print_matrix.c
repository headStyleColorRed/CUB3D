/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:55:25 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/07 22:13:37 by rlabrado         ###   ########.fr       */
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
	exit(-1);
}