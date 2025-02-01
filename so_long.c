#include "so_long.h"
/*
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
*/
int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		simple_error("GAME ALLOCATION FAILED");
	//check_args(argc, argv);
	//read_map(game, argv[1]);  y is number of lines, x is number of columns
	//check_map(game); --> line_length, borders, # of things with saving it to right variable
	//copy_map(game);
	//find location of the player and save is in player_x, player_y
	//flood fill for copy_map, base case is 1, change each place to one, keep decreasing cpy_coin
	//error function takes (game, exit_num, msg); free everything in the game struct 
}