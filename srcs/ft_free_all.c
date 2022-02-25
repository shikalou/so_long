/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:50:34 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/25 18:20:58 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_no_img(t_count *truc)
{
	free(truc);
	exit(0);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_struct(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->link_d);
	mlx_destroy_image(data->mlx, data->link_u);
	mlx_destroy_image(data->mlx, data->link_l);
	mlx_destroy_image(data->mlx, data->link_r);
	mlx_destroy_image(data->mlx, data->rupee);
	mlx_destroy_image(data->mlx, data->rupee2);
	mlx_destroy_image(data->mlx, data->bats);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data);
	free(data);
}
