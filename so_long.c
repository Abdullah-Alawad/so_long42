/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:50:34 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:50:35 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win( t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	check_map_open(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		simple_error("GAME ALLOCATION FAILED");
	set_game_defaults(game);
	read_map(game, argv[1]);
	check_map(game);
	copy_map(game);
	save_player_position(game);
	check_solvability(game);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->x * 50 , game->y * 50, "Lets Steal the GOLD");
	mlx_hook(game->mlx_win, 2, 0L, close_win, game);
	mlx_loop(game->mlx);
	exit_game(game, 0, "so far so good\n");
	//game logic
}

/*
	int fd = open(argv[1], O_RDONLY);
	char	*line = get_next_line(fd);
	int i = 0;
	while(line[i])
	{
		ft_printf("%d\n", line[i]);
		i++;
	} 
*/
