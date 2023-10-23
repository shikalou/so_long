/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:36:34 by ldinaut           #+#    #+#             */
/*   Updated: 2023/10/23 23:15:50 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_printmap2(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->max_liney)
	{
		x = -1;
		while (++x < data->len_linex)
		{
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
					x * 50, y * 50);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->rupee2,
					x * 50, y * 50);
			else if (data->map[y][x] == 'B')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->bats,
					x * 50, y * 50);
		}
	}
}

void	ft_printmap(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->max_liney)
	{
		x = -1;
		while (++x < data->len_linex)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
					x * 50, y * 50);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
					x * 50, y * 50);
			else if (data->map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_d,
					x * 50, y * 50);
				data->p_x = x;
				data->p_y = y;
			}
		}
	}
	ft_printmap2(data);
}
