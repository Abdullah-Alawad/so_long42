/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:50:43 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:50:44 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"

// map measures
# define WIDTH 50
# define HEIGHT 50
// colors
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"
// map 1 sprites
# define S_PLAYER "sprites/ufo_p.xpm"
# define S_WALL "sprites/space_rock.xpm"
# define S_EXIT "sprites/space_exit.xpm"
# define S_COIN "sprites/space_gold.xpm"
# define S_FLOOR "sprites/space_f.xpm"
// map 2 sprites
# define PLAYER "sprites/player.xpm"
# define WALL "sprites/wall.xpm"
# define EXIT "sprites/exit.xpm"
# define COIN "sprites/coin.xpm"
# define FLOOR "sprites/ground.xpm"
// coordinates structure
typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

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
	int		is_solvable;
	int		cpy_coins;
}	t_game;

void	check_args(int argc, char **argv);
void	check_map_open(char *map);
void	simple_error(char *message);
void	exit_game(t_game *game, int EXIT_CODE, char *message);
void	set_game_defaults(t_game *game);
void	read_map(t_game *game, char *map);
void	check_map(t_game *game);
void	copy_map(t_game *game);
void	save_player_position(t_game *game);
void	check_solvability(t_game *game);
void	init_game(t_game *game, char *map_number);
int		close_win(t_game *game);
int		handle_keys(int key_code, t_game *game);
void	set_game_frame(t_game *game);

#endif
