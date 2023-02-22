/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:21:37 by aboncine          #+#    #+#             */
/*   Updated: 2023/02/22 17:37:19 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_create_color_num(char *s, int start)
{
	int		i;
	int		num;
	char	*res;

	i = start;
	while (s[start] != ',' && s[start] != '\n')
		start++;
	res = (char *) malloc(sizeof(char) * start - i + 1);
	start = i;
	i = 0;
	while (s[start] != ',' && s[start] != '\n')
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	num = ft_atoi(res);
	free(res);
	return (num);
}

static unsigned int	ft_color_converter(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	ft_get_rgb(char *s, int start)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = start;
	r = ft_create_color_num(s, i);
	while (s[i] != ',')
		i++;
	i++;
	g = ft_create_color_num(s, i);
	while (s[i] != ',')
		i++;
	i++;
	b = ft_create_color_num(s, i);
	return (ft_color_converter(r, g, b));
}
