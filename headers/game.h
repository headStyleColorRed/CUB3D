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
# define KEY_T			16

# define SQUARE_SIZE	64

typedef struct	s_color
{
	int r_color;
	int g_color;
	int b_color;
}				t_color;

typedef struct s_resolution
{
	int width;
	int height;
}				t_resolution;

typedef struct s_map_textures
{
	char  			*NO_texture;
	char  			*SO_texture;
	char  			*WE_texture;
	char  			*EA_texture;
	char  			*SP_texture;
}				t_map_textures;

typedef struct	s_map
{
	char			*map;
	char			**map_matrix;
	char			*map_file;
	int				map_height;
	int				map_width;
	t_resolution 	resolution;
	t_color			floor_color;
	t_color			ceiling_color;
	t_map_textures	map_textures;
}				t_map;

typedef	enum		e_textures
{
	TEXT_NORTH,
	TEXT_SOUTH,
	TEXT_WEST,
	TEXT_EAST,
	TEXT_SPRITE
}					t_textures;

typedef	struct		s_texture
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}					t_texture;


typedef	struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	void			*img;
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
	char			orientation;

}					t_player_position;

typedef	struct		s_raycasting
{
	t_player_position	player_position;
	t_texture			textures[5];
	int					current_ray;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					celing_color;
	int					wall_color;
	int					floor_color;
	int					move_up;
	int					move_down;
	int					move_right;
	int					move_left;
	int					textures_on;
	int					current_texture;
	double				movement_speed;
	double				rotation_speed;
	double				pos_x;
	double     			pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				time;
	double				old_time;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double 				side_dist_x;
	double 				side_dist_y;
    double 				perp_wall_dist;
	double				old_dir;
	double				old_plane;

	int					text_orient;
	int					text_x;
	int					text_y;
	double				wall_x;
	double				wall_y;


}					t_raycasting;

typedef	struct			s_game
{
	int					is_save;
    t_window    		window;
	t_raycasting		raycast;
	t_map				map;
}						t_game;


/*  G A M E		L O O P  */
void    start_game(t_game *t_game);
void	set_up_window(t_game *game);


/*  I N I T I A L I T A T I O N */

void	initialize_map_variables_1(t_game *game);
void	initialize_map_variables_2(t_game *game);
void	update_orientation(t_game *game, double dir_x, double dir_y, double plane_x, double plane_y);
void	player_orientation(t_game *game);
void	load_ceiling_floor_colors(t_game *game);
int		hexcolor(int r, int g, int b);


/*  G A M E   M O V E M E N T  */
int     pressed_key(int keycode, t_game *game);
int     released_key(int keycode, t_game *game);
int		run_game(t_game *game);
void	set_player_begining_position(t_game *game);


/*  G A M E   D R A W  */
void	put_pxl_to_img(t_game *game, int i, int color, int is_wall);
void 	draw_wall(t_game *game);
void 	draw_floor_and_ceiling(t_game *game);
void	load_textures(t_game *game);


/*  G A M E   D D A  */
void dda_declarations(t_game *game);
void execute_dda(t_game *game);


/*  R A Y C A S T  */
void raycast(t_game *game);

#endif
