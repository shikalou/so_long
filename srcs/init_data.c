/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:39:32 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/24 19:23:42 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_size(int x, int y)
{
	if (x > 52 || y > 26)
	{
		printf("juju le plus bo");
		//free map
		//free struct
		//
	}
}

void	init_img(t_data *data)
{
	int		a;
	int		b;

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
}

t_data	*init_data(int i, char *map, t_count *truc)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	data->map = ft_malloctab(i, map);
	data->max_liney = i;
	data->len_linex = (ft_strlen(data->map[0]) - 1);
	ft_check_size(data->len_linex, data->max_liney);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(0);
	data->mlx_win = mlx_new_window(data->mlx, (data->len_linex * 50),
			(data->max_liney * 50 + 50), "The Legend of Lune");
	init_img(data);
	data->step = 0;
	data->rupee_count = truc->total;
	return (data);
}
