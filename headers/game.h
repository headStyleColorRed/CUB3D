#ifndef GAME_H
#define GAME_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define PI 			3.14159265359

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125
# define KEY_ESC	    53

# define SQUARE_SIZE	64

typedef	struct		s_window
{
	void			*ptr;
	void			*win;
	void			*img_ptr;
	void			*img_str;
	int				height;
	int				width;
}					t_window;

typedef	struct		s_coordinate
{
	int				x;
	int				y;
}					t_coordinate;

typedef	struct		s_player_position
{
	int				x;
	int				y;
	int				x_grid;
	int				y_grid;
	int				dir_x;
	int				dir_y;
}					t_player_position;


typedef	struct		s_raycasting
{
	t_player_position	player_position;
	int		current_ray;
	double	ray_dir_x;
	double	ray_dir_y;
	double	init_ray_dir_x;
	double 	init_ray_dir_y;
	double 	plane_x;	
	double 	plane_y;
	double 	delta_dist_x;
	double	delta_dist_y;

	double	ray_pos_x;
	double	ray_pos_y;
	double	map_x;
	double	delta_dist_x;
	double	delta_dist_y;
	double	camera;
}					t_raycasting;

typedef	struct		s_game
{
    t_window    		window;
	t_raycasting		raycast;
	t_map				*map;
}					t_game;


/*  G A M E		L O O P  */
void    start_game(t_map *map, t_game *t_game);


/*  G A M E   M O V E M E N T  */
int     pressed_key(int keycode, t_game *game);
void    add_key_hooks(t_game *game);
void 	update_movement(t_game *game);


/*  G A M E   D R A W  */
void	new_frame(t_game *game);


/*  G A M E   D D A  */
void	init_raycast(t_game *game);
void	int_dda(t_game *game);

#endif 
