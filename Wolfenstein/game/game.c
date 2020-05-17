
#include "../library.h"

int     pressed_key(int keycode, t_game *game)
{
    (void) game;
    
    if (keycode == KEY_W)
        printf("haleluya");
    return (0);
}

void    add_key_hooks(t_game *game)
{
    mlx_hook(game->window.win,X_EVENT_KEY_PRESS, 0, &pressed_key, game);
}

void    set_up_window(t_map *map, t_window *window)
{
    if (!(window->ptr = mlx_init()))
        print_error("Error initiating mlx");
    if (!(window->win = mlx_new_window(window->ptr, map->resolution.width, map->resolution.length, "Wolfenstein")))
        print_error("Error creating mlx window");
}


void    start_game(t_map *map, t_game *game)
{
    set_up_window(map, &game->window);
    add_key_hooks(game);

    
	mlx_loop(game->window.ptr);
}

void    run_game(t_game *game)
{
    (void)game;
}
