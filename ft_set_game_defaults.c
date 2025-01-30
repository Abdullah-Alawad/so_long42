#include "so_long.h"

void	set_game_defaults(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->exit_img = NULL;
	game->coin_img = NULL;
	game->floor_img = NULL;
	game->map = NULL;
	game->cpy_map = NULL;
	game->p_x = 0;
	game->p_y = 0;
	game->x = 0;
	game->y = 0;
	game->players_num = 0;
	game->coins_num = 0;
	game->exit_num = 0;
	game->moves = 0;
	game->is_solvable = 0;
	game->cpy_coins = 0;
}