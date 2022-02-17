/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:32:16 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/17 15:53:23 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	key_catch(int keycode, t_data *data)
{
	if (keycode == 65307)
		return(win_close(data));
	else if (keycode == 65362 || keycode == 119)

	//else if (keycode == 65361 || keycode == 97)
	//else if (keycode == 65364 || keycode == 115)
	//else if (keycode == 65363 || keycode == 100)
	return (0);
}

int	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L<<0, key_catch, data);
	mlx_hook(data->mlx_win, 33, 1L<<17, win_close, data);
	return (0);
}

/*
up w= 65362 / 119
left a= 65361 / 97
down s= 65364 / 115
right d= 65363 / 100
*/