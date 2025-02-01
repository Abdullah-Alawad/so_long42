#include "so_long.h"

void	check_line_length(t_game *game)
{
	int	len;

	game->x = ft_strlen(game->map[0]);
	while (game->map[game->y])
	{
		len = ft_strlen(game->map[game->y]);
		if (len != game->x)
		{
			exit_game(game, 1, "NOT ALL LINES HAVE THE SAME LENGTH");
		}
		game->y++;
	}
}

void	check_map_borders(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			exit_game(game, 1, "INVALID TOP MAP BORDER");
		i++;
	}
	i = 0;
	while (game->map[game->y - 1][i])
	{
		if (game->map[game->y - 1][i] != '1')
			exit_game(game, 1, "INVALID BOTTOM MAP BORDER");
		i++;
	}
	i = 0;
	while(i < game->y - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
			exit_game(game, 1, "INVALID SIDE MAP BORDER");
		i++;
	}
}

void	check_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C')
				exit_game(game, 1, "INVALID MAP CHARACHTERS ELEMENTS");\
			else if (game->map[i][j] == 'P')
				game->players_num++;
			else if (game->map[i][j] == 'E')
				game->exit_num++;
			else if (game->map[i][j] == 'C')
				game->coins_num++;
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	check_line_length(game);
	check_map_borders(game);
	check_map_elements(game);
	if (game->players_num != 1 || game->exit_num != 1 || game->coins_num < 1)
		exit_game(game, 1, "INVALID MAP ELEMENTS");
}
