#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <X11/keysym.h>
//# include <mlx.h>

// map measures
# define WIDTH 50
# define HEIGHT 50
// colors
# define RED "\033[1;31m"
# define RESET "\033[0m"
// sprites
# define PLAYER "sprites/player.xpm"
# define WALL "sprites/wall.xpm"
# define EXIT "sprites/exit.xpm"
# define COIN "sprites/coin.xpm"
# define FLOOR "sprites/ground.xpm"

// game structure
typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*coin_img;
	void	*floor_img;
	char	**map;
	char	**cpy_map;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		players_num;
	int		coins_num;
	int		exit_num;
	int		moves;
	int		is_solvable;
	int		cpy_coins;
}	t_game;
#endf