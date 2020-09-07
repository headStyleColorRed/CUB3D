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

# define WINX 1024
# define WINY 768

typedef	struct		s_window
{
	void			*ptr;
	void			*win;
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
}					t_player_position;

typedef struct 	s_raycasting
{
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			help;
	int			x_text;
	int			y_text;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	double		walldist;
	double		x_olddir;
	double		x_oldplane;
	double		ms;
	double		rs;
	double		x_wall;
	double		x_floor;
	double		y_floor;
	double		x_curfloortext;
	double		y_curfloortext;
	double		curdist;
	double		weight;
}				t_raycasting;

typedef	struct		s_game
{
    t_window    		window;
	t_player_position	player_position;
	t_map				*map;
	t_raycasting		raycast;
}					t_game;


void    start_game(t_map *map, t_game *t_game);

void	 	dda_init(t_game *game);
void	 	dda(t_game *game);
void		draw_wall(int x, int start, int end, t_game *game);
void	 	floor_and_ceiling(t_game *game, int x);
void		move_side(t_game *game);
int			move(t_game *game);
void		wolf3d_init(t_game *game);
void	 	ray_casting_init(t_game *game, int x);
void	 	ray_casting(t_game *game);
#endif 
