#include "so_long.h"

int	is_possible_move(t_game *game, int new_y, int new_x)
{
	if (new_y < 0 || new_y >= game->y || new_x < 0 || new_x >= game->x)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->coins_num > 0)
	{
		ft_printf(GREEN "[HINT] YOU MUST BE GREEDY PIRATE!\n");
		return (0);
	}
	return (1);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	static int	moves = 0;

	if (is_possible_move(game, new_y, new_x))
	{
		moves++;
		ft_printf(BLUE "Moves: %d\n", moves);
		if (game->map[new_y][new_x] == 'C')
			game->coins_num -= 1;
		if (game->map[new_y][new_x] == 'E' && game->coins_num == 0)
			exit_game(game, 0, "YOU WON PIRATE!");
		game->map[game->p_y][game->p_x] = '0';
		game->map[new_y][new_x] = 'P';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img,
			game->p_x * WIDTH, game->p_y * HEIGHT);
		game->p_y = new_y;
		game->p_x = new_x;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img,
			game->p_x * WIDTH, game->p_y * HEIGHT);
	}
}

int	handle_keys(int key_code, t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->p_y;
	new_x = game->p_x;
	if (key_code == XK_Escape)
		close_win(game);
	else if (key_code == XK_Left || key_code == XK_a)
		new_x--;
	else if (key_code == XK_Right || key_code == XK_d)
		new_x++;
	else if (key_code == XK_Up || key_code == XK_w)
		new_y--;
	else if (key_code == XK_Down || key_code == XK_s)
		new_y++;
	move_player(game, new_y, new_x);
	return (0);
}
