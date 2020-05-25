
#include "../library.h"

int     pressed_key(int keycode, t_game *game)
{
    // check_for_movement()
    
    if (keycode == KEY_W ||
        keycode == KEY_S ||
        keycode == KEY_D ||
        keycode == KEY_A )
        check_for_movement(game, keycode);
        
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

int    run_game(t_game *game)
{
    (void)game;
     apply_raycast(game);
    // draw_sprites();
    // show_image();
    
    return (0);
}


void    start_game(t_map *map, t_game *game)
{
    set_up_window(map, &game->window);
	game->map = map;
    add_key_hooks(game);

    
	mlx_loop_hook(game->window.ptr, &run_game, game);
	mlx_loop(game->window.ptr);
}
