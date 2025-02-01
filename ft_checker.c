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
