/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:15:38 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/23 13:49:21 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

char	*read_map(t_map *raw_map)
{
	int		fd;
	int		i;
	char	buffer;
	char	*map;
	int		ft;

	ft = open(raw_map->map_file, O_RDONLY);
	if (ft == -1)
		print_error("Not found .cub file");
	map = (char *)ft_calloc(4065, 1);
	if (!map)
		print_error("Allocation error");
	i = 0;
	while ((fd = read(ft, &buffer, 1)))
		map[i++] = buffer;
	close(fd);
	return (map);
}

void	check_map_is_dot_cub(char *map_file)
{
	int i;

	i = ft_strlen(map_file);
	if (map_file[i - 1] != 'b' &&
		map_file[i - 2] != 'u' &&
		map_file[i - 3] != 'c')
		print_error("File is not .cub");
}

void	process_file(char *map_file, t_map *map)
{
	char *raw_map;

	check_map_is_dot_cub(map_file);
	map->map_file = map_file;
	raw_map = read_map(map);
	parse_cube_map(raw_map, map);
	check_file_conformity(map);
	transform_file_to_matrix(map);
}

void	file_processor(int argc, char **argv, t_game *game)
{
	int i;

	i = 0;
	game->is_save = 0;
	if (argc == 2)
		process_file(argv[MAP_PATH], &game->map);
	else if (argc == 3)
		save_game(argv, game);
	else
		print_error("Not enough arguments, map missing");
}
