/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:49:37 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/24 19:51:08 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../library.h"

void	create_bmp_header(t_bitmap *bitmap, t_game *game)
{

	ft_bzero(bitmap->header, BITMAP_SIZE);

	// Bitmap signature
	bitmap->header[0] = (unsigned char)('B');
    bitmap->header[1] = (unsigned char)('M');

	bitmap->height = game->window.height = 100;
	bitmap->width = game->window.width = 100;
	// File size
	bitmap->size = BITMAP_SIZE + (bitmap->height * bitmap->width * 4);
	ft_memset(&bitmap->header[2], (int)bitmap->size, 1);					// The entire file size
	ft_memset(&bitmap->header[10], (int)BITMAP_SIZE, 1);					// Size of header
	ft_memset(&bitmap->header[14], (int)40, 1);								// Header size
	ft_memset(&bitmap->header[18], (int)bitmap->width, 1);					// Image width
	ft_memset(&bitmap->header[22], (int)bitmap->height, 1);					// Image height
	ft_memset(&bitmap->header[26], (short)1, 1);							// Color Planes (?)
	ft_memset(&bitmap->header[28], (short)32, 1);							// Bits per pixel
	ft_memset(&bitmap->header[34], (short)bitmap->size, 1);					// Image size
}

void	write_file(t_bitmap *bitmap, int fd)
{
	int row, column;

    bitmap->pixels = malloc(bitmap->size);
    for(row = bitmap->height - 1; row >= 0; row--) {
        for(column = 0; column < bitmap->width; column++) {
            int p = (row * bitmap->width + column) * 4;
            bitmap->pixels[p + 0] = 64; //blue
            bitmap->pixels[p + 1] = 128;//green
            bitmap->pixels[p + 2] = 192;//red
        }
    }

	write(fd, bitmap->header, 54);
    write(fd, bitmap->pixels, bitmap->size);
    free(bitmap->pixels);
    close(fd);
}

/*
**	save_process()
**	1. We read the map as usual
**	2. Start the game and save the first frame
**	3. Open the file where the bpm image will be drawn
**	4. Create the file header
**
*/

void	save_process(char **arguments, t_game *game)
{
	int			fd;
	t_bitmap	bitmap;

	process_file(arguments[MAP_PATH], &game->map);
	start_game(game);
	if ((fd = open("gamefile.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 0777)) < 0)
		print_error("Saving game file opening error");

    // -- FILE HEADER -- //
	create_bmp_header(&bitmap, game);
	write_file(&bitmap, fd);

}

void	save_game(char **arguments, t_game *game)
{
	if (ft_strncmp("--save", arguments[SAVE_FILE], 7) != 0)
		print_error("Second argument '--save' incorrect");
	game->is_save = 1;
	save_process(arguments, game);
}
