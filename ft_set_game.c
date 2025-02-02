/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:51:57 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:51:58 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	save_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_y = i;
				game->p_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
