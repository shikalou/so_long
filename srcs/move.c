/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:16:55 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/23 18:38:01 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_d(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] != '1')
	{
		if (data->map[data->p_y + 1][data->p_x] != 'E')
		{
			if (data->map[data->p_y + 1][data->p_x] == 'C')
			{
				data->map[data->p_y + 1][data->p_x] = '0';
				data->rupee_count--;
			}
			ft_put_d(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				win_close(data);
				ft_putstr_fd("well done :)\n", 1);
			}
			else
				ft_printf("there's still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}

int	ft_move_u(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] != '1')
	{
		if (data->map[data->p_y - 1][data->p_x] != 'E')
		{
			if (data->map[data->p_y - 1][data->p_x] == 'C')
			{
				data->map[data->p_y - 1][data->p_x] = '0';
				data->rupee_count--;
			}
			ft_put_u(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				win_close(data);
				ft_putstr_fd("well done :)\n", 1);
			}
			else
				ft_printf("there's still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}

int	ft_move_r(t_data *data)
{
	if (data->map[data->p_y][data->p_x + 1] != '1')
	{
		if (data->map[data->p_y][data->p_x + 1] != 'E')
		{
			if (data->map[data->p_y][data->p_x + 1] == 'C')
			{
				data->map[data->p_y][data->p_x + 1] = '0';
				data->rupee_count--;
			}
			ft_put_r(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				win_close(data);
				ft_putstr_fd("well done :)\n", 1);
			}
			else
				ft_printf("there's still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}

int	ft_move_l(t_data *data)
{
	if (data->map[data->p_y][data->p_x - 1] != '1')
	{
		if (data->map[data->p_y][data->p_x - 1] != 'E')
		{
			if (data->map[data->p_y][data->p_x - 1] == 'C')
			{
				data->map[data->p_y][data->p_x - 1] = '0';
				data->rupee_count--;
			}
			ft_put_l(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				win_close(data);
				ft_putstr_fd("well done :)\n", 1);
			}
			else
				ft_printf("there's still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}
