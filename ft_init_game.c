#include "so_long.h"

void	init_images_1(t_game *game)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER, &w, &h);
	if (!game->player_img)
		exit_game(game, 1, "PLAYER IMAGE ALLOCATION FAILED");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &w, &h);
	if (!game->wall_img)
		exit_game(game, 1, "WALL IMAGE ALLOCATION FAILED");
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &w, &h);
	if (!game->exit_img)
		exit_game(game, 1, "EXIT IMAGE ALLOCATION FAILED");
	game->coin_img = mlx_xpm_file_to_image(game->mlx, COIN, &w, &h);
	if (!game->coin_img)
		exit_game(game, 1, "COIN IMAGE ALLOCATION FAILED");
	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR, &w, &h);
	if (!game->floor_img)
		exit_game(game, 1, "FLOOR IMAGE ALLOCATION FAILED");
}

void	init_images_2(t_game *game)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	game->player_img = mlx_xpm_file_to_image(game->mlx, S_PLAYER, &w, &h);
	if (!game->player_img)
		exit_game(game, 1, "PLAYER IMAGE ALLOCATION FAILED");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, S_WALL, &w, &h);
	if (!game->wall_img)
		exit_game(game, 1, "WALL IMAGE ALLOCATION FAILED");
	game->exit_img = mlx_xpm_file_to_image(game->mlx, S_EXIT, &w, &h);
	if (!game->exit_img)
		exit_game(game, 1, "EXIT IMAGE ALLOCATION FAILED");
	game->coin_img = mlx_xpm_file_to_image(game->mlx, S_COIN, &w, &h);
	if (!game->coin_img)
		exit_game(game, 1, "COIN IMAGE ALLOCATION FAILED");
	game->floor_img = mlx_xpm_file_to_image(game->mlx, S_FLOOR, &w, &h);
	if (!game->floor_img)
		exit_game(game, 1, "FLOOR IMAGE ALLOCATION FAILED");
}

void	transform(t_game *game, int i, int j, t_coords coords)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall_img, coords.x, coords.y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit_img, coords.x, coords.y);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->coin_img, coords.x, coords.y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player_img, coords.x, coords.y);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor_img, coords.x, coords.y);
}

void	set_game_frame(t_game *game)
{
	int			i;
	int			j;
	t_coords	coords;

	i = 0;
	coords.y = 0;
	while (i < game->y)
	{
		j = 0;
		coords.x = 0;
		while (j < game->x)
		{
			transform(game, i, j, coords);
			j++;
			coords.x += WIDTH;
		}
		i++;
		coords.y += HEIGHT - 1;
	}
}

void	init_game(t_game *game, char *map_number)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, 1, "MLX INIT FAILED");
	game->mlx_win = mlx_new_window(game->mlx, game->x * WIDTH,
			game->y * (HEIGHT - 1), "Steal The GOLD Pirate");
	if (!game->mlx_win)
		exit_game(game, 1, "MLX WINDOW CREATION FAILED");
	if (map_number[0] == '1')
		init_images_1(game);
	else
		init_images_2(game);
	set_game_frame(game);
	mlx_hook(game->mlx_win, 17, 0, close_win, game);
	mlx_key_hook(game->mlx_win, handle_keys, game);
	mlx_loop(game->mlx);
}
