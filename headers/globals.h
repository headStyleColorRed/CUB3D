/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:56:20 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/05 12:56:25 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef globals_h
#define globals_h

typedef enum e_map_parser
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	RESOLUTION,
	SPRITE,
	FLOOR,
	CEILING,
	MAP
}			t_map_parser;

typedef enum e_bool
{
	ft_false,
	ft_true
}			t_bool;

char	*map_textures(t_map_parser chosenMap);
#endif 
