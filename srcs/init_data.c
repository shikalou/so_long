/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:39:32 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/23 18:22:01 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*new_data(int i, char *map, t_count *truc)
{
	t_data	*data;
	int		a;
	int		b;

	data = malloc(sizeof(t_data));
	data->map = ft_malloctab(i, map);
	data->max_liney = i;
	data->len_linex = (ft_strlen(data->map[0]) - 1);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->len_linex * 50),
			(data->max_liney * 50 + 50), "The Legend of Lune");
	data->floor = mlx_xpm_file_to_image(data->mlx, "img/floor.xpm", &a, &b);
	data->wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &a, &b);
	data->exit = mlx_xpm_file_to_image(data->mlx, "img/exit3.xpm", &a, &b);
	data->link_d = mlx_xpm_file_to_image(data->mlx, "img/link-d.xpm", &a, &b);
	data->link_u = mlx_xpm_file_to_image(data->mlx, "img/link-u.xpm", &a, &b);
	data->link_l = mlx_xpm_file_to_image(data->mlx, "img/link-l.xpm", &a, &b);
	data->link_r = mlx_xpm_file_to_image(data->mlx, "img/link-r.xpm", &a, &b);
	data->rupee = mlx_xpm_file_to_image(data->mlx, "img/rupee.xpm", &a, &b);
	data->rupee2 = mlx_xpm_file_to_image(data->mlx, "img/rupee2.xpm", &a, &b);
	data->bats = mlx_xpm_file_to_image(data->mlx, "img/ennemy.xpm", &a, &b);
	data->step = 0;
	data->rupee_count = truc->total;
	return (data);
}
