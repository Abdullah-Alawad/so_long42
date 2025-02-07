/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:50:17 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:50:19 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	int	param_len;

	if (argc < 3)
	{
		ft_printf(RED"[ERROR] MAP FILE OR MAP NUMBER MISSING\n"RESET);
		ft_printf(BLUE"EXPECTED: ./so_long <mapfile> <map_number>\n"RESET);
		ft_printf(BLUE"FOR MAP NUMBER CHOOSE BETWEEN 1 & 2\n"RESET);
		exit(1);
	}
	else if (argc > 3)
	{
		ft_printf(RED"[ERROR] TOO MANY ARGUMENTS\n"RESET);
		ft_printf(BLUE"EXPECTED: ./so_long <mapfile> <map_number>\n"RESET);
		ft_printf(BLUE"FOR MAP NUMBER CHOOSE BETWEEN 1 & 2\n"RESET);
		exit(1);
	}
	param_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][param_len - 4], ".ber", 4))
	{
		ft_printf(RED"[ERROR] INVALID FILE EXTENSION\n"RESET);
		ft_printf(BLUE"EXPECTED: <map>.ber\n"RESET);
		exit(1);
	}
	if (ft_strlen(argv[2]) != 1)
	{
		ft_printf(RED"[ERROR] INVALID MAP NUMBER\n"RESET);
		ft_printf(BLUE"EXPECTED: ONE NUMBER ONLY 1 OR 2\n"RESET);
		exit(1);
	}
	if (argv[2][0] != '1' && argv[2][0] != '2')
	{
		ft_printf(RED"[ERROR] INVALID MAP NUMBER\n"RESET);
		ft_printf(BLUE"EXPECTED: ONE NUMBER ONLY 1 OR 2\n"RESET);
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
