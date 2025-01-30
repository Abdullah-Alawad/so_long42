#include "so_long.h"

void	simple_error(char *message)
{
	ft_printf(RED"[ERROR] %s\n"RESET, message);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}