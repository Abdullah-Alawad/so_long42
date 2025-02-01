#include "so_long.h"

int	count_lines(char *map)
{
	int		fd;
	int		num_lines;
	char	*line;

	num_lines = 0;
	fd = open(map, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		num_lines++;
		free(line);
	}
	close(fd);
	return (num_lines);
}

void	free_map_while_reading(char **map, int len, int fd)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
	loop_fd(fd);
	simple_error("MAP ALLOCATION FAILED");
}

// ft_strdup here is modified from the original, if line ends with '\n' it will be removed
void	add_map_to_struct(char *map, t_game *game)
{
	int		fd;
	int 	num_lines;
	int		line_no;
	char	*line;

	num_lines = count_lines(map);
	game->map = malloc(sizeof(char *) * (num_lines + 1));
	if (!game->map)
		simple_error("MAP ALLOCATION FAILED");
	game->map[num_lines] = NULL;
	fd = open(map, O_RDONLY);
	line_no = 0;
	while ((line = get_next_line(fd)) != NULL && line_no < num_lines)
	{
		game->map[line_no] = ft_strdup(line);
		free(line);
		if (!game->map[line_no])
			free_map_while_reading(game->map, line_no, fd);
		line_no++;
	}
	close(fd);
}
