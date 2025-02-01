#include "so_long.h"

int	count_lines(char *map)
{
	int		fd;
	int		num_lines;
	char	*line;

	fd = open(map, O_RDONLY);
	num_lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		num_lines++;
		free(line);
	}
	close(fd);
	return (num_lines);
}

void	loop_fd(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
}

// ft_strdup here is modified from the original, if line ends with '\n' it will be removed
void	add_lines(t_game *game, char *map, int num_lines)
{
	int		fd;
	int		line_no;
	char	*line;

	fd = open(map, O_RDONLY);
	line_no = 0;
	while ((line = get_next_line(fd)) != NULL && line_no < num_lines)
	{
		game->map[line_no] = ft_strdup(line);
		free(line);
		if (!game->map[line_no])
		{
			while (line_no >= 0)
				free(game->map[line_no--]);
			loop_fd(fd);
			exit_game(game, 1, "MAP ALLOCATION FAILED");
		}
		line_no++;
	}
	if (!game->map[0])
		exit_game(game, 1, "EMPTY MAP");
	close(fd);
}

void	read_map(t_game *game, char *map)
{
	int 	num_lines;

	num_lines = count_lines(map);
	game->map = malloc(sizeof(char *) * (num_lines + 1));
	if (!game->map)
		exit_game(game, 1, "MAP ALLOCATION FAILED");
	game->map[num_lines] = NULL;
	add_lines(game, map, num_lines);
}
