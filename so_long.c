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
	if (argv[2][0] == '1')
		init_game_1(game);
	else
		init_game_2(game);
}
