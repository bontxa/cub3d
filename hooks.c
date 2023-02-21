#include "cub3d.h"

static void	ft_moveup_or_down(t_cub3d *box, int flag)
{
	double	playercos;
	double	playersin;
	double	newx;
	double	newy;

	playercos = cos(ft_degrees_to_radiants(box->angle)) * 0.2;
	playersin = sin(ft_degrees_to_radiants(box->angle)) * 0.2;
	if (flag == 0)
	{
		newx = box->player_x + playercos;
		newy = box->player_y + playersin;
		if (box->map[(int)floor(newy)][(int)floor(newx)] == 48)
		{
			box->player_x = newx;
			box->player_y = newy;
		}
	}
	else
	{
		newx = box->player_x - playercos;
		newy = box->player_y - playersin;
		if (box->map[(int)floor(newy)][(int)floor(newx)] == 48)
		{
			box->player_x = newx;
			box->player_y = newy;
		}
	}
}

int	ft_handlekeys(int ks, t_cub3d *box)
{
	printf("key -> %d\n", ks);
	mlx_clear_window(box->mlx_ptr, box->win_ptr);
	if (ks == KEY_A)
		box->angle -= 5;
	if (ks == KEY_D)
		box->angle += 5;
	if (ks == KEY_W)
		ft_moveup_or_down(box, 0);
	if (ks == KEY_S)
		ft_moveup_or_down(box, 1);
	if (ks == KEY_ESC)
	{
		ft_free_n_exit(box);
	}
	ft_raycasting(box);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
	return (0);
}
