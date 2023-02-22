/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:43:17 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 17:10:17 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error_n_free(t_cub3d *box, char **strarr, char *str)
{
	free(box->path_to_east);
	free(box->path_to_west);
	free(box->path_to_north);
	free(box->path_to_south);
	ft_print_error(str, strarr);
}

void	ft_start_game(char **argv)
{
	t_cub3d	box;

	ft_init_struct(&box);
	ft_create_map(&box, argv[1]);
	ft_check_map(&box);
	ft_where_to_start(&box);
	ft_create_window(&box);
	ft_create_image(&box.img, box);
	ft_init_text(&box);
	ft_raycasting(&box);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img.img_ptr, 0, 0);
	mlx_key_hook(box.win_ptr, ft_handlekeys, &box);
	mlx_loop(box.mlx_ptr);
}

void	check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i--;
	if (argv[i] != 'b')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
	i--;
	if (argv[i] != 'u')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
	i--;
	if (argv[i] != 'c')
	{
		printf("Error\nMappa non valida\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_cub(argv[1]);
		ft_start_game(argv);
	}
	write(2, "Error\nparametri non validi\n", 28);
}
