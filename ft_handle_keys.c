#include "so_long.h"

int	handle_keys(int key_code, t_game *game)
{
	if (key_code == XK_Escape)
		close_win(game);
	else if (key_code == XK_Left || key_code == XK_a)
		ft_printf("LEFT\n");
	else if (key_code == XK_Right || key_code == XK_d)
		ft_printf("RIGHT\n");
	else if (key_code == XK_Up || key_code == XK_w)
		ft_printf("UP\n");
	else if (key_code == XK_Down || key_code == XK_s)
		ft_printf("DOWN\n");
	return (0);
}