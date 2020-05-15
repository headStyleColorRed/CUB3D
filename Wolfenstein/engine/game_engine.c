
#include "../library.h"

void    set_up_window(t_map *map, t_window *window)
{
    if (!(window->ptr = mlx_init()))
        print_error("Error initiating mlx");
    if (!(window->win = mlx_new_window(window->ptr, map->resolution.width, map->resolution.length, "Wolfenstein")))
        print_error("Error creating mlx window");
    printf("height: %d", map->map_width);
}

void    start_game(t_map *map, t_window *window)
{
    printf("height: %d", map->map_width);
    set_up_window(map, window);
    mlx_loop(window->ptr);
}

