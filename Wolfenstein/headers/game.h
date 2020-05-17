#ifndef GAME_H
#define GAME_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125
# define KEY_ESC	    53

typedef	struct		s_window
{
	void			*ptr;
	void			*win;
}					t_window;

typedef	struct		s_coordinate
{
	int			*x;
	int			*y;
}					t_coordinate;


typedef	struct		s_game
{
    t_window    	window;
	t_coordinate	player_position;
}					t_game;


/*  G A M E   E N G I N E */
void    start_game(t_map *map, t_game *t_game);

#endif 
