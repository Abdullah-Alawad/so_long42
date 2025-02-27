/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalawad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:51:36 by aalawad           #+#    #+#             */
/*   Updated: 2025/02/02 14:51:51 by aalawad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_till_rn(const char *s)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n' && s[i] != '\r')
		i++;
	dup = (char *)malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

int	count_lines(char *map)
{
	int		fd;
	int		num_lines;
	char	*line;

	fd = open(map, O_RDONLY);
	num_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (num_lines);
}

void	loop_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	add_lines(t_game *game, char *map, int num_lines)
{
	int		fd;
	int		line_no;
	char	*line;

	fd = open(map, O_RDONLY);
	line_no = 0;
	line = get_next_line(fd);
	while (line && line_no < num_lines)
	{
		game->map[line_no] = ft_strdup_till_rn(line);
		free(line);
		line = get_next_line(fd);
		if (!game->map[line_no])
		{
			line_no--;
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
	int	num_lines;

	num_lines = count_lines(map);
	game->map = malloc(sizeof(char *) * (num_lines + 1));
	if (!game->map)
		exit_game(game, 1, "MAP ALLOCATION FAILED");
	game->map[num_lines] = NULL;
	add_lines(game, map, num_lines);
}
