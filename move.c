/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:16:55 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/17 19:13:53 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_d(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_d, (data->p_x * 50), (data->p_y * 50 + 50));
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->p_x * 50), (data->p_y * 50));
		data->p_y++;
		data->step++;
		printf("step count = %d\n", data->step);
	}
	return (0);
}

int	ft_move_u(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_u, (data->p_x * 50), (data->p_y * 50 - 50));
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->p_x * 50), (data->p_y * 50));
		data->p_y--;
		data->step++;
		printf("step count = %d\n", data->step);
	}
	return (0);
}

int	ft_move_r(t_data *data)
{
	if (data->map[data->p_y][data->p_x + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_r, (data->p_x * 50 + 50), (data->p_y * 50));
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->p_x * 50), (data->p_y * 50));
		data->p_x++;
		data->step++;
		printf("step count = %d\n", data->step);
	}
	return (0);
}

int	ft_move_l(t_data *data)
{
	if (data->map[data->p_y][data->p_x - 1] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_l, (data->p_x * 50 - 50), (data->p_y * 50));
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, (data->p_x * 50), (data->p_y * 50));
		data->p_x--;
		data->step++;
		printf("step count = %d\n", data->step);
	}
	return (0);
}