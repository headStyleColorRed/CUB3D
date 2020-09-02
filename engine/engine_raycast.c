#include "../library.h"

void draw_pixel(t_game *game, t_coordinate *pos, int color)
{
	if (pos->x >= 0 && pos->x < game->map->resolution.width && pos->y >= 0 && pos->y < game->map->resolution.height)
	{

		*(int *)(game->window.ptr + (4 * (int)game->map->resolution.width * (int)pos->y) + ((int)pos->x * 4)) = color;
	}
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
		draw_pixel(game, &pos, color)
	}
	


}

void apply_raycast(t_game *game)
{
    // while (i < game->map->resolution.width)
    // {
    //     j = 0;
    //     while (j < game->map->resolution.height)
    //     {
    //         mlx_pixel_put(game->window.ptr, game->window.win, i, j++, 1921280);
    //     }
    //     i++;
    // }

	int     bpp;
	int     size_line;
	int     endian;

	void	*image_pointer;
	char 	*my_image_data;

	image_pointer = (void *)mlx_new_image(game->window.ptr, game->map->resolution.width, game->map->resolution.height);

	my_image_data = mlx_get_data_addr(image_pointer, &bpp, &size_line, &endian);


	mlx_put_image_to_window(game->window.ptr, game->window.win, my_image_data, 0, 0);
    

}