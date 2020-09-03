#include "../library.h"

void draw_pixel(t_game *game, t_coordinate *pix_pos, int color)
{
	(void)game;
	(void)pix_pos;
	(void)color;
}

int draw_vertical_line(t_game *game, t_coordinate *start, int height, int color)
{
	int					i;
	int					j;
	t_coordinate		pos;
	int					limit;

	if (start->x < 0 || start->x > game->map->resolution.height)
		return (1);
	
	pos.x = start->x;
	limit = game->map->resolution.height;

	i = 0;
	while (i < height && (j = start->y + i) < limit)
	{
		pos.y = j;
		draw_pixel(game, &pos, color);
	}
	return (0);
}

void apply_raycast(t_game *game)
{
	int     bpp;
	int     size_line;
	int     endian;

	void	*image_pointer;
	char 	*my_image_data;

	image_pointer = (void *)mlx_new_image(game->window.ptr, game->map->resolution.width, game->map->resolution.height);

	my_image_data = mlx_get_data_addr(image_pointer, &bpp, &size_line, &endian);

	mlx_put_image_to_window(game->window.ptr, game->window.win, my_image_data, 0, 0);

	// char **myMatrix;


    

}

// void	fill_my_matrix(char **myMatrix)
// {	
// 	myMatrix = (int)ft_calloc(5, sizeof(int));
	
// 	for(int i = 0; i < 5; i++) {
// 		for(int j = 0; j < 4; j++) {
// 			printf("[%d][%d]\n", i, j);
// 		}
// 	}
// }