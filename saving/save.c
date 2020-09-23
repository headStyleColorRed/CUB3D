/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:49:37 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/23 14:21:01 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../library.h"

/*
**	save_process()
**	1. We read the map as usual
**	2. Start the game and save the first frame
**
**
**
*/

void	save_process(char **arguments, t_game *game)
{
	int fd;

	process_file(arguments[MAP_PATH], &game->map);
	start_game(game);
	if ((fd = open("gamefile.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 0777)) < 0)
		print_error("Saving game file opening error");



}

void	save_game(char **arguments, t_game *game)
{
	if (ft_strncmp("--save", arguments[SAVE_FILE], 7) != 0)
		print_error("Second argument '--save' incorrect");
	game->is_save = 1;
	save_process(arguments, game);
}
