#include "cub3d.h"

static void	ft_render_column_piece(t_img img, int start, int end, int color, int nb)
{
	while (start < end)
	{
		ft_render_pixel(img, nb, start, color);
		start++;
	}
}

static void	ft_render_column(t_img img, t_column column, int flag)
{
	int	start;
	int	end;
	int	color;

	if (flag == 0)
	{
		start = column.sky_start;
		end = column.sky_end;
		color = column.sky_color;
	}
	else if (flag == 1)
	{
		start = column.wall_start;
		end = column.wall_end;
		color = column.wall_color;
	}
	else
	{
		start = column.floor_start;
		end = column.floor_end;
		color = column.floor_color;
	}
	ft_render_column_piece(img, start, end, color, column.colnbr);
}

static void	ft_render_wall(t_img *texture, t_img img, t_column column)
{
	unsigned int	color;
	double			textx;
	double			stepx;
	double			texty;
	int				i;

	i = 0;
	stepx = 64.0 / (column.wall_end - column.wall_start);
	textx = 0;
	texty = 64.0 * (column.currentx + column.currenty);
	while (column.wall_start < column.wall_end)
	{
		color = ft_mlx_pixel_get(texture, (int)texty % 64, (int)textx % 64);
		ft_render_pixel(img, column.colnbr, column.wall_start, color);
		column.wall_start++;
		textx += stepx;
		i++;
	}
	texture->currenty += stepx / 64;
}

static void	ft_render_walls(t_cub3d *box, t_img img, t_column column)
{
	if (column.direction == 0)
		ft_render_wall(&box->north, img, column);
	else if (column.direction == 1)
		ft_render_wall(&box->south, img, column);
	else if (column.direction == 2)
		ft_render_wall(&box->east, img, column);
	else
		ft_render_wall(&box->west, img, column);
}

void	ft_render_full_column(t_cub3d *box, t_img img, t_column column)
{
	ft_render_column(img, column, 0);
	ft_render_walls(box, img, column);
	ft_render_column(img, column, 2);
}
