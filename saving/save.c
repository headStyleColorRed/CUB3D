/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:49:37 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/25 21:48:35 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../library.h"

void		int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)i;
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}


void	create_bmp_header(t_bitmap *bitmap, t_game *game, int fd)
{
	unsigned char	header[54];
	int				filesize;
	int				ps;

	ps = ((4 - (bitmap->width * 3) % 4) % 4);
	filesize = 54 + (game->window.width * 3 * game->window.height) + (ps * game->window.width);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, game->window.width);
	int_to_char(header + 22, -game->window.height);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
	write(fd, game->window.img_ptr, game->window.width * game->window.height * 4);
}

void	print_bmp_pixels(t_bitmap *bitmap, t_game *game, int fd)
{
	int				x;
	int				y;
	unsigned char *pixels = malloc(bitmap->size);
	(void)game;

	y = bitmap->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < bitmap->width)
		{
			int p = (x * bitmap->width + y) * 4;
            pixels[p + 0] = 64; //blue
            pixels[p + 1] = 128;//green
            pixels[p + 2] = 192;//red
			x++;
		}
		y--;
	}
    write(fd, bitmap->pixels, bitmap->size);
    close(fd);


}

void	save_process(char **arguments, t_game *game)
{
	int			fd;
	t_bitmap	bitmap;

	process_file(arguments[MAP_PATH], &game->map);
	start_game(game);
	if ((fd = open("gamefile.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 0777)) < 0)
		print_error("Saving game file opening error");

    // -- FILE HEADER -- //
	create_bmp_header(&bitmap, game, fd);
	close(fd);

}

void	save_game(char **arguments, t_game *game)
{
	if (ft_strncmp("--save", arguments[SAVE_FILE], 7) != 0)
		print_error("Second argument '--save' incorrect");
	game->is_save = 1;
	save_process(arguments, game);
}
