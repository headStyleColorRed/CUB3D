#include "../library.h"

void draw_pixel(t_game *game, t_coordinate *pix_pos, int color)
{
	(void)game;
	(void)pix_pos;
	(void)color;
}

int draw_vertical_line(t_game *game, t_coordinate *start, int height, int color)
{
	int i;
	int j;
	t_coordinate pos;
	int limit;

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

// void print_matrix(char **matrix, int height, int width)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (i < height) {
// 		j = 0;
// 		while (j < width) {
// 			printf("%c ", matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

int grid_is_wall(char **matrix, t_ray ray)
{
	if (matrix[ray.y_grid][ray.x_grid] == '1')
	{
		printf("Wall at x:%d - y:%d\n", ray.y_grid, ray.x_grid);
		return 1;
	}
	else
		return 0;
}

double f_tan(int num)
{
	(void)num;
	return 1.73205;
}

int calculate_raycast(t_game *game)
{

	int height = 4;
	int width = 4;
	(void)game;

	// print_matrix(game->map->map_matrix, game->map->map_height, game->map->map_width);

	//      #   #     #   # I N I T I A L I Z E  #   #    #   #

	// Rows
	char **matrix = malloc(height * sizeof(int *));

	// Cols
	for (int i = 0; i < height; i++)
		matrix[i] = malloc(width * sizeof(int));

	// Fill
	int print = '0';
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			print = i == 0 ? '1' : '0';
			matrix[i][j] = print;
		}
	}
	matrix[3][1] = 'N';

	// Print
	// for (int i = 0; i < height; i++)
	// {
	// 	for (int j = 0; j < height; j++)
	// 	{
	// 		printf("%c ", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }

	//      #   #     #   #  R A Y C A S T  #   #    #   #

	int				is_up;
	int				in_loop;
	int				wall_height;
	t_ray			old_ray;
	t_ray			new_ray;
	t_coordinate	subsequent;

	wall_height = 64;
	is_up = 1;
	subsequent.y = is_up ? wall_height : wall_height * -1;
	subsequent.x = wall_height / f_tan(60);

	// First Point
	old_ray.y = ((224 / wall_height) * wall_height - 1);
	old_ray.x = 96 + ((224 - old_ray.y) / f_tan(60));

	old_ray.y_grid = old_ray.y / wall_height;
	old_ray.x_grid = old_ray.x / wall_height;

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

		new_ray.y = old_ray.y + (subsequent.y * -1);
		new_ray.x = old_ray.x + subsequent.x;

		new_ray.y_grid = new_ray.y / wall_height;
		new_ray.x_grid = new_ray.x / wall_height;
		in_loop = 1;
	}
	return (0);
}


void apply_raycast(t_game *game)
{
	int bpp;
	int size_line;
	int endian;

	void *image_pointer;
	char *my_image_data;

	image_pointer = (void *)mlx_new_image(game->window.ptr, game->map->resolution.width, game->map->resolution.height);

	my_image_data = mlx_get_data_addr(image_pointer, &bpp, &size_line, &endian);

	mlx_put_image_to_window(game->window.ptr, game->window.win, my_image_data, 0, 0);

	calculate_raycast(game);
}