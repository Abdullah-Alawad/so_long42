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
	init_game(game, argv[2]);
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
