#ifndef GAME_H
#define GAME_H

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125
# define KEY_ESC	    53

typedef	struct	s_window
{
	void		*ptr;
	void		*win;
}				t_window;

typedef	struct	s_game
{
    t_window    window;
}				t_game;


/*  G A M E   E N G I N E */
void    start_game(t_map *map, t_game *t_game);

#endif 
