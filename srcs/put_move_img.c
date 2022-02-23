/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_move_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:36:17 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/23 17:36:25 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_d(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_d,
		(data->p_x * 50), (data->p_y * 50 + 50));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
		(data->p_x * 50), (data->p_y * 50));
	data->p_y++;
	data->step++;
}

void	ft_put_u(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_u,
		(data->p_x * 50), (data->p_y * 50 - 50));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
		(data->p_x * 50), (data->p_y * 50));
	data->p_y--;
	data->step++;
}

void	ft_put_r(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_r,
		(data->p_x * 50 + 50), (data->p_y * 50));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
		(data->p_x * 50), (data->p_y * 50));
	data->p_x++;
	data->step++;
}

void	ft_put_l(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_l,
		(data->p_x * 50 - 50), (data->p_y * 50));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
		(data->p_x * 50), (data->p_y * 50));
	data->p_x--;
	data->step++;
}
