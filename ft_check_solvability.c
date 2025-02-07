/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solvability.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:51:04 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:51:05 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_e(t_game *game, int py, int px)
{
	if (py < 0 || px < 0 || py > (game->y - 1) || px > (game->x - 1))
		return ;
	if (game->cpy_map[py][px] == '1')
		return ;
	if (game->cpy_map[py][px] == 'E')
		game->is_solvable = 1;
	game->cpy_map[py][px] = '1';
	flood_fill_e(game, py - 1, px);
	flood_fill_e(game, py + 1, px);
	flood_fill_e(game, py, px - 1);
	flood_fill_e(game, py, px + 1);
}

void	flood_fill_c(t_game *game, int py, int px)
{
	if (py < 0 || px < 0 || py > (game->y - 1) || px > (game->x - 1))
		return ;
	if (game->cpy_map[py][px] == '1')
		return ;
	if (game->cpy_map[py][px] == 'C')
		game->cpy_coins = game->cpy_coins - 1;
	game->cpy_map[py][px] = '1';
	flood_fill_c(game, py - 1, px);
	flood_fill_c(game, py + 1, px);
	flood_fill_c(game, py, px - 1);
	flood_fill_c(game, py, px + 1);
}

void	check_solvability(t_game *game)
{
	game->cpy_coins = game->coins_num;
	flood_fill_e(game, game->p_y, game->p_x);
	if (!game->is_solvable)
		exit_game(game, 1, "GAME IS NOT SOLVABLE, CAN'T REACH THE EXIT");
	free_map(game->cpy_map);
	copy_map(game);
	set_e_to_1(game);
	flood_fill_c(game, game->p_y, game->p_x);
	if (game->cpy_coins != 0)
		exit_game(game, 1, "GAME IS NOT SOLVABLE, CAN'T REACH ALL COINS");
}
