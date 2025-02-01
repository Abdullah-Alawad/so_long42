#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		simple_error("GAME ALLOCATION FAILED");
	set_game_defaults(game);
	check_map_shape(argv[1]);
	check_map_borders(argv[1], game);
	ft_printf("I'am here");
}