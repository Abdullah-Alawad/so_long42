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

int	close_win(t_game *game)
{
	exit_game(game, 0, "GAME QUITED SUCCESSFULLY");
	return (0);
}

void	remove_images(t_game *game)
{
	if (game->cat_down)
		mlx_destroy_image(game->mlx, game->cat_down);
	if (game->cat_up)
		mlx_destroy_image(game->mlx, game->cat_up);
	if (game->cat_left)
		mlx_destroy_image(game->mlx, game->cat_left);
	if (game->cat_right)
		mlx_destroy_image(game->mlx, game->cat_right);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->coin_img)
		mlx_destroy_image(game->mlx, game->coin_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
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
		remove_images(game);
		if (game->map)
			free_map(game->map);
		if (game->cpy_map)
			free_map(game->cpy_map);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
	if (EXIT_CODE == 0)
		ft_printf(GREEN"%s\n"RESET, message);
	else
		ft_printf(RED"[ERROR] %s\n"RESET, message);
	exit(EXIT_CODE);
}
