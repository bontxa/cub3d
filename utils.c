#include "cub3d.h"

void	ft_print_error(char *str)
{
	printf("%s", str);
	exit(0);
}

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_map(t_cub3d *box)
{
	int	i;

	i = 0;
	while (box->map[i])
		free(box->map[i++]);
	free(box->map);
}

void	ft_perror_exit(char *str)
{
	perror(str);
	exit (1);
}

double	ft_degrees_to_radiants(double degrees)
{
	return (degrees * PI / 180);
}
