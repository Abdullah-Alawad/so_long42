#include "so_long.h"

void	init_images(t_game *game)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	game->cat_down = mlx_xpm_file_to_image(game->mlx, CAT_DOWN, &w, &h);
	if (!game->cat_down)
		exit_game(game, 1, "CAT DOWN IMAGE ALLOCATION FAILED");
	game->cat_up = mlx_xpm_file_to_image(game->mlx, CAT_UP, &w, &h);
	if (!game->cat_up)
		exit_game(game, 1, "CAT UP IMAGE ALLOCATION FAILED");
	game->cat_left = mlx_xpm_file_to_image(game->mlx, CAT_LEFT, &w, &h);
	if (!game->cat_left)
		exit_game(game, 1, "CAT LEFT IMAGE ALLOCATION FAILED");
	game->cat_right = mlx_xpm_file_to_image(game->mlx, CAT_RIGHT, &w, &h);
	if (!game->cat_right)
		exit_game(game, 1, "CAT RIGHT IMAGE ALLOCATION FAILED");
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
			game->cat_down, coords.x, coords.y);
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
		coords.y += HEIGHT;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, 1, "MLX INIT FAILED");
	game->mlx_win = mlx_new_window(game->mlx, game->x * WIDTH,
			game->y * (HEIGHT), "Steal The GOLD & Stay Away from the ROCKS");
	if (!game->mlx_win)
		exit_game(game, 1, "MLX WINDOW CREATION FAILED");
	init_images(game);
	set_game_frame(game);
	mlx_hook(game->mlx_win, 17, 0, close_win, game);
	mlx_key_hook(game->mlx_win, handle_keys, game);
	mlx_loop(game->mlx);
}
