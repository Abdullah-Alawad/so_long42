/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:51:27 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:51:29 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	simple_error(char *message)
{
	ft_printf(RED"[ERROR] %s\n"RESET, message);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game, int EXIT_CODE, char *message)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->cpy_map)
			free_map(game->cpy_map);
		free(game);
	}
	if (EXIT_CODE == 0)
		ft_printf(GREEN"%s\n"RESET, message);
	else
		ft_printf(RED"[ERROR] %s\n"RESET, message);
	exit(EXIT_CODE);
}
