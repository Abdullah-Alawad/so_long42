#include "so_long.h"

void	check_args(int argc, char **argv)
{
	int	param_len;

	if (argc < 2)
	{
		ft_printf(RED"[ERROR] MAP FILE MISSING\n"RESET);
		ft_printf(BLUE"EXPECTED: ./so_long <mapfile>\n"RESET);
		exit(1);
	}
	else if (argc > 2)
	{
		ft_printf(RED"[ERROR] TOO MANY ARGUMENTS\n"RESET);
		ft_printf(BLUE"EXPECTED: ./so_long <mapfile>\n"RESET);
		exit(1);
	}
	param_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][param_len - 4], ".ber", 4))
	{
		ft_printf(RED"[ERROR] INVALID FILE EXTENSION\n"RESET);
		ft_printf(BLUE"EXPECTED: <map>.ber\n"RESET);
		exit(1);
	}
}

void	check_map_open(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"[ERROR] MAP FILE NOT FOUND\n"RESET);
		exit(1);
	}
	close(fd);
}

void	loop_fd(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
}

void	check_map_valid(char *map)
{
	int		fd;
	int		line_len;
	int 	loop_len;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		loop_len = ft_strlen(line);
		if (line[loop_len - 1] == '\n')
			loop_len--;
		free(line);
		if (line_len != loop_len)
		{
			loop_fd(fd);
			ft_printf(RED"[ERROR] INVALID MAP SIZE\n"RESET);
			ft_printf(BLUE"EXPECTED: RECTANGULAR MAP\n"RESET);
			exit(1);
		}
	}
	close(fd);
}

void	check_map_shape(char *map)
{
	check_map_open(map);
	if (count_lines(map) == 0)
	{
		ft_printf(RED"[ERROR] EMPTY MAP\n"RESET);
		exit(1);
	}
	check_map_valid(map);
}