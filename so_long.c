#include "so_long.h"
#include <stdio.h>
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
	int i = 0;
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	check_map(game);
	exit_game(game, 0, "so far so good\n");
	//copy_map(game);
	//find location of the player and save is in player_x, player_y
	//flood fill for copy_map, base case is 1, change each place to one, keep decreasing cpy_coin
	//error function takes (game, exit_num, msg); free everything in the game struct 
}