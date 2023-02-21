#include "cub3d.h"

static void	ft_create_map_2(t_cub3d *box, int count, int fd)
{
	int		i;

	i = 0;
	box->map = (char **) malloc(sizeof(char *) * (count + 1));
	if (!box->map)
		ft_perror_exit("Error allocation memory");
	close(fd);
	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error:");
	while (i < count)
		box->map[i++] = get_next_line(fd);
	box->map[i] = 0;
	close(fd);
}

void	ft_create_map(t_cub3d *box)
{
	int		fd;
	int		count;
	char	*tmp;

	count = 0;
	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error:");
	tmp = get_next_line(fd);
	if (tmp != NULL)
		count++;
	else
		ft_perror_exit("Map is NULL, error is:");
	while (tmp != NULL)
	{
		free (tmp);
		tmp = get_next_line(fd);
		count++;
	}
	ft_create_map_2(box, count, fd);
}

void	ft_init_struct(t_cub3d *box)
{
	box->width = 800;
	box->height = 600;
	box->half_h = box->height / 2;
	box->half_w = box->width / 2;
	box->rdelay = 30;
	box->fov = 66;
	box->half_fov = 0;
	box->player_x = 2;
	box->player_y = 2;
	box->angle = 360;
	box->rc_precision = 64;
	box->rc_incrementing = box->fov / box->width;
	box->half_fov = box->fov / 2;
}
