#include "so_long.h"

int count_map_lines(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}