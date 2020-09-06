#include "../library.h"

void draw_vertical_line(t_game *game)
{

	int bpp;
	int size_line;
	int endian;

	void *image_pointer;
	char *my_image_data;

	image_pointer = (void *)mlx_new_image(game->window.ptr, game->map->resolution.width, game->map->resolution.height);

	my_image_data = mlx_get_data_addr(image_pointer, &bpp, &size_line, &endian);

	mlx_put_image_to_window(game->window.ptr, game->window.win, my_image_data, 0, 0);
}

int grid_is_wall(char **matrix, t_ray ray)
{
	if (matrix[ray.y_grid][ray.x_grid] == '1')
	{
		printf("Wall at x:%d - y:%d\n", ray.x_grid, ray.y_grid);
		return 1;
	}
	else
		return 0;
}

double radians(int num)
{
	return num * PI / 180.0;
}

int calculate_raycast(t_game *game)
{
	int				is_up;
	int				in_loop;
	char			**matrix;
	t_ray			old_ray;
	t_ray			new_ray;
	t_coordinate	subsequent;

	is_up = 1;
	subsequent.y = is_up ? SQUARE_SIZE * -1 : SQUARE_SIZE;
	subsequent.x = SQUARE_SIZE / tan(radians(60));
	matrix = game->map->map_matrix;

	// First Point
	old_ray.y = ((game->player_position.y / SQUARE_SIZE) * SQUARE_SIZE - 1);
	old_ray.x = game->player_position.x + ((game->player_position.y - old_ray.y) / tan(radians(60)));

	old_ray.y_grid = old_ray.y / SQUARE_SIZE;
	old_ray.x_grid = old_ray.x / SQUARE_SIZE;

	if (grid_is_wall(matrix, old_ray))
		return 0;

	// Subsequent Points
	in_loop = 0;
	new_ray = old_ray;
	while (!grid_is_wall(matrix, new_ray))
	{
		if (in_loop)
		{
			old_ray.y = new_ray.y;
			old_ray.x = new_ray.x;
		}

		new_ray.y = old_ray.y + subsequent.y;
		new_ray.x = old_ray.x + subsequent.x;

		new_ray.y_grid = new_ray.y / SQUARE_SIZE;
		new_ray.x_grid = new_ray.x / SQUARE_SIZE;
		in_loop = 1;
	}
	return (0);
}


void apply_raycast(t_game *game)
{
	calculate_raycast(game);
	// draw_vertical_line(game);
}