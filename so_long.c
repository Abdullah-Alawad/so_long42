#include "so_long.h"

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
	check_map(game);
	copy_map(game);
	exit_game(game, 0, "so far so good\n");
	//find location of the player and save is in player_x, player_y
	//flood fill for copy_map, base case is 1, change each place to one, keep decreasing cpy_coin
	//error function takes (game, exit_num, msg); free everything in the game struct 
}

/*
	int fd = open(argv[1], O_RDONLY);
	char	*line = get_next_line(fd);
	int i = 0;
	while(line[i])
	{
		ft_printf("%d\n", line[i]);
		i++;
	} 
*/