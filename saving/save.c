/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:49:37 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/24 18:42:12 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../library.h"

void	create_bmp_header(t_bitmap *bitmap, t_game *game, int fd)
{
	int		size;
    int row, column;
	(void)fd;
	ft_bzero(bitmap->header, BITMAP_SIZE);

	// Bitmap signature
	bitmap->header[0] = (unsigned char)('B');
    bitmap->header[1] = (unsigned char)('M');

	game->window.height = 100;
	game->window.width = 100;
	// File size
	size = BITMAP_SIZE + (game->window.height * game->window.width * 4);
	ft_memset(&bitmap->header[2], (int)size, 1);
	ft_memset(&bitmap->header[10], (int)BITMAP_SIZE, 1);
	ft_memset(&bitmap->header[14], (int)40, 1);
	ft_memset(&bitmap->header[18], (int)game->window.height, 1);
	ft_memset(&bitmap->header[22], (int)game->window.width, 1);
	ft_memset(&bitmap->header[26], (short)1, 1);
	ft_memset(&bitmap->header[28], (short)32, 1);
	ft_memset(&bitmap->header[34], (short)size, 1);


	unsigned char *pixels = malloc(size);
    for(row = game->window.height - 1; row >= 0; row--) {
        for(column = 0; column < game->window.width; column++) {
            int p = (row * game->window.width + column) * 4;
            pixels[p + 0] = 64; //blue
            pixels[p + 1] = 128;//green
            pixels[p + 2] = 192;//red
        }
    }

    FILE *fout = fopen("32bit.bmp", "wb");
    fwrite(bitmap->header, 1, 54, fout);
    fwrite(pixels, 1, size, fout);
    free(pixels);
    fclose(fout);

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
	create_bmp_header(&bitmap, game, fd);


}

void	save_game(char **arguments, t_game *game)
{
	if (ft_strncmp("--save", arguments[SAVE_FILE], 7) != 0)
		print_error("Second argument '--save' incorrect");
	game->is_save = 1;
	save_process(arguments, game);
}
