#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <X11/keysym.h>
//# include <mlx.h>

// map measures
# define WIDTH 50
# define HEIGHT 50
// colors
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
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

void	check_args(int argc, char **argv);
void	check_map_open(char *map);
void	loop_fd(int fd);
void	check_map_valid(char *map);
void	check_map_shape(char *map);
void	simple_error(char *message);
void	free_map(char ***map);
//check remove 3 below
void	check_first_line(t_game *game);
void	check_last_line(t_game *game);
void	check_sides(t_game *game);
void	check_map_borders(char *map, t_game *game);
int		count_lines(char *map);
void	free_map_while_reading(char **map, int len, int fd);
void	add_map_to_struct(char *map, t_game *game);
void	set_game_defaults(t_game *game);
int 	count_map_lines(char **map);

#endif