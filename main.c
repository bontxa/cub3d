#include "cub3d.h"

//UTILS

// void	ft_print_error(char *str)
// {
// 	printf("%s", str);
// 	exit(0);
// }

// int ft_strlen(char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	ft_free_map(t_cub3d *box)
// {
// 	int	i;

// 	i = 0;
// 	while (box->map[i])
// 		free(box->map[i++]);
// 	free(box->map);
// }

// void	ft_perror_exit(char *str)
// {
// 	perror(str);
// 	exit (1);
// }

// double	ft_degrees_to_radiants(double degrees)
// {
// 	return (degrees * PI / 180);
// }

//MAPPA

// static void	ft_create_map_2(t_cub3d *box, int count, int fd)
// {
// 	int		i;

// 	i = 0;
// 	box->map = (char **) malloc(sizeof(char *) * (count + 1));
// 	if (!box->map)
// 		ft_perror_exit("Error allocation memory");
// 	close(fd);
// 	fd = open("map.cub", O_RDONLY);
// 	if (fd < 0)
// 		ft_perror_exit("Error:");
// 	while (i < count)
// 		box->map[i++] = get_next_line(fd);
// 	box->map[i] = 0;
// 	close(fd);
// }

// void	ft_create_map(t_cub3d *box)
// {
// 	int		fd;
// 	int		count;
// 	char	*tmp;

// 	count = 0;
// 	fd = open("map.cub", O_RDONLY);
// 	if (fd < 0)
// 		ft_perror_exit("Error:");
// 	tmp = get_next_line(fd);
// 	if (tmp != NULL)
// 		count++;
// 	else
// 		ft_perror_exit("Map is NULL, error is:");
// 	while (tmp != NULL)
// 	{
// 		free (tmp);
// 		tmp = get_next_line(fd);
// 		count++;
// 	}
// 	ft_create_map_2(box, count, fd);
// }

// //INIT

// void	ft_init_struct(t_cub3d *box)
// {
// 	box->width = 800;
// 	box->height = 600;
// 	box->half_h = box->height / 2;
// 	box->half_w = box->width / 2;
// 	box->rdelay = 30;
// 	box->fov = 66;
// 	box->half_fov = 0;
// 	box->player_x = 2;
// 	box->player_y = 2;
// 	box->angle = 360;
// 	box->rc_precision = 64;
// 	box->rc_incrementing = box->fov / box->width;
// 	box->half_fov = box->fov / 2;
// }

// unsigned int	ft_mlx_pixel_get(t_img *data, int x, int y)
// {
// 	char	*dst;

// 	dst = data->data + (y * data->line_len + x * (data->bpp / 8));
// 	return (*(unsigned int *)dst);
// }

// void	ft_init_text(t_cub3d *box)
// {
// 	box->north.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, "north.xpm", &box->north.w, &box->north.h);
// 	box->north.data = mlx_get_data_addr(box->north.img_ptr, &box->north.bpp, &box->north.line_len, &box->north.endian);
// 	box->south.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, "south.xpm", &box->south.w, &box->south.h);
// 	box->south.data = mlx_get_data_addr(box->south.img_ptr, &box->south.bpp, &box->south.line_len, &box->south.endian);
// 	box->east.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, "east.xpm", &box->east.w, &box->east.h);
// 	box->east.data =  mlx_get_data_addr(box->east.img_ptr, &box->east.bpp, &box->east.line_len, &box->east.endian);
// 	box->west.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, "west.xpm", &box->west.w, &box->west.h);
// 	box->west.data =  mlx_get_data_addr(box->west.img_ptr, &box->west.bpp, &box->west.line_len, &box->west.endian);
// 	box->west.currenty = 0;
// 	box->east.currenty = 0;
// 	box->south.currenty = 0;
// 	box->north.currenty = 0;
// }

// //CREAZIONE FINESTRA

// void	ft_create_window(t_cub3d *box)
// {
// 	box->height = 600;
// 	box->width = 800;
// 	box->mlx_ptr = mlx_init();
// 	box->win_ptr = mlx_new_window(box->mlx_ptr, box->width, box->height, "cub3d");
// }

// void	ft_create_image(t_img *img, t_cub3d box)
// {
// 	img->img_ptr = mlx_new_image(box.mlx_ptr, box.width, box.height);
// 	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
// }

// //RENDERING

// void	ft_render_pixel(t_img img, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = img.data + (y * img.line_len + x * (img.bpp / 8));
// 	*(unsigned int *) dst = color;
// }

// void	ft_render_column_piece(t_img img, int start, int end, int color, int nb)
// {
// 	while (start < end)
// 	{
// 		ft_render_pixel(img, nb, start, color);
// 		start++;
// 	}
// }

// void	ft_render_column(t_img img, t_column column, int flag)
// {
// 	int	start;
// 	int	end;
// 	int	color;

// 	if (flag == 0)
// 	{
// 		start = column.sky_start;
// 		end = column.sky_end;
// 		color = column.sky_color;
// 	}
// 	else if (flag == 1)
// 	{
// 		start = column.wall_start;
// 		end = column.wall_end;
// 		color = column.wall_color;
// 	}
// 	else
// 	{
// 		start = column.floor_start;
// 		end = column.floor_end;
// 		color = column.floor_color;
// 	}
// 	ft_render_column_piece(img, start, end, color, column.colnbr);
// }

// void	ft_render_wall(t_img *texture, t_img img, t_column column)
// {
// 	unsigned int	color;
// 	double			textx;
// 	double			stepx;
// 	double			texty;
// 	int				i;

// 	i = 0;
// 	stepx = 64.0 / (column.wall_end - column.wall_start);
// 	textx = 0;
// 	texty = 64.0 * (column.currentx + column.currenty);
// 	while (column.wall_start < column.wall_end)
// 	{
// 		color = ft_mlx_pixel_get(texture, (int)texty % 64, (int)textx % 64);
// 		ft_render_pixel(img, column.colnbr, column.wall_start, color);
// 		column.wall_start++;
// 		textx += stepx;
// 		i++;
// 	}
// 	texture->currenty += stepx / 64;
// }

// void	ft_render_walls(t_cub3d *box, t_img img, t_column column)
// {
// 	if (column.direction == 0)
// 		ft_render_wall(&box->north, img, column);
// 	else if (column.direction == 1)
// 		ft_render_wall(&box->south, img, column);
// 	else if (column.direction == 2)
// 		ft_render_wall(&box->east, img, column);
// 	else
// 		ft_render_wall(&box->west, img, column);
// }

// void	ft_render_full_column(t_cub3d *box, t_img img, t_column column)
// {
// 	ft_render_column(img, column, 0);
// 	ft_render_walls(box, img, column);
// 	ft_render_column(img, column, 2);
// }

//RAYCASTING

// void	ft_get_direction(t_cub3d *box, t_ray *ray)
// {
// 	if (ray->raycos < 0)
// 		ray->raycos *= -1;
// 	if (ray->raysin < 0)
// 		ray->raysin *= -1;
// 	if (box->map[(int)((ray->currenty)- ray->raysin)][(int)ray->currentx] != '1')
// 		ray->direction = 0;
// 	else if (box->map[(int)((ray->currenty) + ray->raysin)][(int)ray->currentx] != '1')
// 		ray->direction = 1;
// 	else if (box->map[(int)(ray->currenty)][(int)((ray->currentx) + ray->raycos)] != '1')
// 		ray->direction = 2;
// 	else if (box->map[(int)(ray->currenty)][(int)((ray->currentx) - ray->raycos)] != '1')
// 		ray->direction = 3;
// }

// t_column	ft_do_column(t_cub3d *box, t_ray ray, int raycount)
// {
// 	t_column	res;

// 	res.sky_start = 0;
// 	res.sky_end = box->half_h - ray.wallheight;
// 	if (res.sky_end < 0)
// 		res.sky_end = 0;
// 	res.sky_color = 0x007FFF;
// 	res.wall_start = box->half_h - ray.wallheight;
// 	if (res.wall_start < 0)
// 		res.wall_start = 0;
// 	res.wall_end = box->half_h + ray.wallheight;
// 	if (res.wall_end >= box->height)
// 		res.wall_end = box->height;
// 	res.direction = ray.direction;
// 	res.floor_start = box->half_h + ray.wallheight;
// 	if (res.floor_start >= box->height)
// 		res.floor_start = box->height;
// 	res.floor_end = box->height;
// 	res.colnbr = raycount;
// 	res.currentx = ray.currentx;
// 	res.currenty = ray.currenty;

// 	return (res);
// }

// void	ft_init_ray(t_cub3d *box, t_ray *ray)
// {
// 	ray->currentx = box->player_x;
// 	ray->currenty = box->player_y;
// 	ray->raycos = cos(ft_degrees_to_radiants(ray->ray_angle)) / box->rc_precision;
// 	ray->raysin = sin(ft_degrees_to_radiants(ray->ray_angle)) / box->rc_precision;
// }

// void	ft_raycasting(t_cub3d *box)
// {
// 	int			raycount;
// 	int			wall;
// 	t_ray		ray;
// 	t_column	currentcol;

// 	raycount = 0;
// 	ray.ray_angle = box->angle - box->half_fov;
// 	while (raycount < box->width)
// 	{
// 		wall = 48;
// 		ft_init_ray(box, &ray);
// 		while (wall == 48)
// 		{
// 			ray.currentx += ray.raycos;
// 			ray.currenty += ray.raysin;
// 			wall = box->map[(int)floor(ray.currenty)][(int)floor(ray.currentx)];
// 		}
// 		ray.dist = sqrt(pow(box->player_x - ray.currentx, 2) + pow(box->player_y - ray.currenty, 2));
// 		ray.dist = ray.dist * cos(ft_degrees_to_radiants(ray.ray_angle - box->angle));
// 		ray.wallheight = floor(box->half_h /ray.dist);
// 		ft_get_direction(box, &ray);
// 		currentcol = ft_do_column(box, ray, raycount);
// 		ft_render_full_column(box, box->img, currentcol);
// 		ray.ray_angle += box->rc_incrementing;
// 		raycount++;
// 	}
// }

//HOOKS

// void	ft_moveup_or_down(t_cub3d *box, int flag)
// {
// 	double	playercos;
// 	double	playersin;
// 	double	newx;
// 	double	newy;

// 	playercos = cos(ft_degrees_to_radiants(box->angle)) * 0.2;
// 	playersin = sin(ft_degrees_to_radiants(box->angle)) * 0.2;
// 	if (flag == 0)
// 	{
// 		newx = box->player_x + playercos;
// 		newy = box->player_y + playersin;
// 		if (box->map[(int)floor(newy)][(int)floor(newx)] == 48)
// 		{
// 			box->player_x = newx;
// 			box->player_y = newy;
// 		}
// 	}
// 	else
// 	{
// 		newx = box->player_x - playercos;
// 		newy = box->player_y - playersin;
// 		if (box->map[(int)floor(newy)][(int)floor(newx)] == 48)
// 		{
// 			box->player_x = newx;
// 			box->player_y = newy;
// 		}
// 	}
// }

// int	ft_handlekeys(int ks, t_cub3d *box)
// {
// 	printf("key -> %d\n", ks);
// 	mlx_clear_window(box->mlx_ptr, box->win_ptr);
// 	mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
// 	ft_create_image(&box->img, *box);
// 	if (ks == KEY_A)
// 		box->angle -= 5;
// 	if (ks == KEY_D)
// 		box->angle += 5;
// 	if (ks == KEY_W)
// 		ft_moveup_or_down(box, 0);
// 	if (ks == KEY_S)
// 		ft_moveup_or_down(box, 1);
// 	if (ks == KEY_ESC)
// 		exit(0);
// 	ft_raycasting(box);
// 	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
// 	return (0);
// }

//GIOCO

void	ft_start_game(void)
{
	t_cub3d	box;

	ft_init_struct(&box);
	ft_create_map(&box);
	ft_check_map(&box);
	ft_create_window(&box);
	ft_create_image(&box.img, box);
	ft_init_text(&box);
	ft_raycasting(&box);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img.img_ptr, 0, 0);
	mlx_key_hook(box.win_ptr, ft_handlekeys, &box);
	mlx_loop(box.mlx_ptr);
}

int	main()
{
	ft_start_game();
}
