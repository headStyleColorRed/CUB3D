/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:19:36 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/25 21:47:23 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	D O C U M E N T A T I O N
**
** 	https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393
**
*/

#ifndef SAVE_H
#define SAVE_H

# define BITMAP_SIZE 	 54

typedef	struct		s_bitmap
{
	int				height;
	int				width;
	int				size;
	unsigned char			header[BITMAP_SIZE];
	unsigned char	*pixels;
}					t_bitmap;

/*  B I T M A P   S A V E  */
void	save_game(char **arguments, t_game *game);
void	save_process(char **arguments, t_game *game);

#endif
