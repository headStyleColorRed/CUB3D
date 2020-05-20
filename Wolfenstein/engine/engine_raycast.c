#include "../library.h"

void apply_raycast(t_game *game)
{
	int i;
	int j;

    i = 0;
    j = 0;
	
    while (i < game->map->resolution.width)
    {
        j = 0;
        while (j < game->map->resolution.length)
        {
            mlx_pixel_put(game->window.ptr, game->window.win, i, j++, 1921280);
        }
        i++;
    }
    

}