#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "game.h"

typedef struct 	s_raycaster
{
	int			project_plane_dimension;
	int			center_of_projection_plane;
	int			distance_to_projection_plane;
	double		angle_between_rays;
}				t_raycaster;

typedef struct  s_ray
{
    int x;
    int y;
    int x_grid;
    int y_grid;
}               t_ray;

/*  G A M E   E N G I N E */
void	check_for_movement(t_game *game, int keycode);

void	apply_raycast(t_game *game);

#endif 
