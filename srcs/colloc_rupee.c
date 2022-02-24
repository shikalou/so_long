/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colloc_rupee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:45:36 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/24 16:30:37 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collec_rupee_d(t_data *data)
{
	data->map[data->p_y + 1][data->p_x] = '0';
	data->rupee_count--;
}

void	ft_collec_rupee_u(t_data *data)
{
	data->map[data->p_y - 1][data->p_x] = '0';
	data->rupee_count--;
}

void	ft_collec_rupee_r(t_data *data)
{
	data->map[data->p_y][data->p_x + 1] = '0';
	data->rupee_count--;
}

void	ft_collec_rupee_l(t_data *data)
{
	data->map[data->p_y][data->p_x - 1] = '0';
	data->rupee_count--;
}

void	ft_loose(t_data *data)
{
	ft_printf("step count = %d\n", data->step + 1);
	write(1, "you loose :(\n", 14);
	win_close(data);
}
