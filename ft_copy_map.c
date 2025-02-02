/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:51:15 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:51:19 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game)
{
	int	line_no;

	line_no = 0;
	game->cpy_map = malloc(sizeof(char *) * (game->y + 1));
	if (!game->cpy_map)
		exit_game(game, 1, "COPY MAP ALLOCAION FAILED");
	game->cpy_map[game->y] = NULL;
	while (line_no < game->y)
	{
		game->cpy_map[line_no] = ft_strdup(game->map[line_no]);
		if (!game->cpy_map[line_no])
		{
			line_no--;
			while (line_no >= 0)
				free(game->cpy_map[line_no--]);
			exit_game(game, 1, "COPY MAP ALLOCATION FAILED");
		}
		line_no++;
	}
}
