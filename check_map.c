/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:12:56 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/21 16:30:41 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_do_check(t_cub3d *box, int tmp)
{
	while (box->map[box->j])
	{
		ft_first_check(box, tmp);
		while (box->map[box->j][box->i])
		{
			ft_second_check(box);
			if (box->map[box->j][box->i] == ' ')
				ft_check_valid_path(box, box->j, box->i, box->number_of_rows);
			box->i++;
		}
		box->i = 0;
		box->j++;
	}
	if (box->flag == 0)
		ft_print_error("errore: punto di partenza non definito\n");
	printf("check concluso, mappa valida\n");
}

void	ft_check_map(t_cub3d *box)
{
	box->i = 0;
	box->j = 0;
	box->number_of_rows = 0;
	box->flag = 0;
	int	tmp;
	while (box->map[box->j])
	{
		box->number_of_rows++;
		box->j++;
	}
	tmp = box->number_of_rows;
	while (tmp != 0 && box->map[tmp - 1][0] != '\n')
		tmp--;
	box->j = tmp;
	ft_do_check(box, tmp);
}
