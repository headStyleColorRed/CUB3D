
#include "../library.h"

void    add_key_hooks()
{

}

void    set_up_window(t_map *map, t_window *window)
{
    if (!(window->ptr = mlx_init()))
        print_error("Error initiating mlx");
    if (!(window->win = mlx_new_window(window->ptr, map->resolution.width, map->resolution.length, "Wolfenstein")))
        print_error("Error creating mlx window");
    mlx_loop(window->ptr);
}


void    start_game(t_map *map, t_game *game)
{
    set_up_window(map, &game->window);
    add_key_hooks();
}

