#include "so_long.h"

void	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
		{
			free_map(&game->map);
			simple_error("INVALID MAP");
		}
		i++;
	}
}

void	check_last_line(t_game *game)
{
	int	map_len;
	int	i;

	map_len = count_map_lines(game->map);
	map_len--;
	i = 0;
	while (game->map[map_len][i])
	{
		if (game->map[map_len][i] != '1')
		{
			free_map(&game->map);
			simple_error("INVALID MAP");
		}
		i++;
	}
}

void	check_sides(t_game *game)
{
	int	map_len;
	int	i;

	map_len = count_map_lines(game->map);
	map_len -= 2;
	i = 1;
	while (i <= map_len)
	{
		if(game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 1] != '1')
		{
			free_map(&game->map);
			simple_error("INVALID MAP");
		}
		i++;
	}

}

void	check_map_borders(char *map, t_game *game)
{
	add_map_to_struct(map, game);
	check_first_line(game);
	check_last_line(game);
	check_sides(game);
}