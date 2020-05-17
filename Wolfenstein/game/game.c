
#include "../library.h"

int     pressed_key(int keycode, t_game *game)
{
    (void) game;
    
    if (keycode == KEY_W)
        game->player_position.y -= 5;
    else if (keycode == KEY_S)
        game->player_position.y += 5;
    else if (keycode == KEY_D)
        game->player_position.x += 5;
    else if (keycode == KEY_A)
        game->player_position.x -= 5;
        
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
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            mlx_pixel_put(game->window.ptr, game->window.win, game->player_position.x + i, game->player_position.y + j++, 1921280);
        }
        i++;
    }
    
    
    return (0);
}


void    start_game(t_map *map, t_game *game)
{
    set_up_window(map, &game->window);
    add_key_hooks(game);

    
	mlx_loop_hook(game->window.ptr, &run_game, game);
	mlx_loop(game->window.ptr);
}
