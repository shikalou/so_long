/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:16:55 by ldinaut           #+#    #+#             */
/*   Updated: 2023/10/23 23:15:50 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_d(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] != '1')
	{
		if (data->map[data->p_y + 1][data->p_x] == 'B')
			ft_loose(data);
		if (data->map[data->p_y + 1][data->p_x] != 'E')
		{
			if (data->map[data->p_y + 1][data->p_x] == 'C')
				ft_collec_rupee_d(data);
			ft_put_d(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				ft_printf("step count = %d\n", data->step + 1);
				ft_putstr_fd("well done :)\n", 1);
				win_close(data);
			}
			else
				ft_printf("still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}

int	ft_move_u(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] != '1')
	{
		if (data->map[data->p_y - 1][data->p_x] == 'B')
			ft_loose(data);
		if (data->map[data->p_y - 1][data->p_x] != 'E')
		{
			if (data->map[data->p_y - 1][data->p_x] == 'C')
				ft_collec_rupee_u(data);
			ft_put_u(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				ft_printf("step count = %d\n", data->step + 1);
				ft_putstr_fd("well done :)\n", 1);
				win_close(data);
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
		if (data->map[data->p_y][data->p_x + 1] == 'B')
			ft_loose(data);
		if (data->map[data->p_y][data->p_x + 1] != 'E')
		{
			if (data->map[data->p_y][data->p_x + 1] == 'C')
				ft_collec_rupee_r(data);
			ft_put_r(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				ft_printf("step count = %d\n", data->step + 1);
				ft_putstr_fd("well done :)\n", 1);
				win_close(data);
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
		if (data->map[data->p_y][data->p_x - 1] == 'B')
			ft_loose(data);
		if (data->map[data->p_y][data->p_x - 1] != 'E')
		{
			if (data->map[data->p_y][data->p_x - 1] == 'C')
				ft_collec_rupee_l(data);
			ft_put_l(data);
			ft_printf("step count = %d\n", data->step);
		}
		else
		{
			if (data->rupee_count == 0)
			{
				ft_printf("step count = %d\n", data->step + 1);
				ft_putstr_fd("well done :)\n", 1);
				win_close(data);
			}
			else
				ft_printf("there's still %d rupee left!\n", data->rupee_count);
		}
	}
	return (0);
}
