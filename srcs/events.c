/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:32:16 by ldinaut           #+#    #+#             */
/*   Updated: 2023/10/23 23:15:50 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	string_put(t_data *data)
{
	char	*step;
	char	*s;
	char	*str;
	int		c;

	s = "step count = ";
	c = 0xffffff;
	step = ft_itoa(data->step);
	str = ft_strjoin(s, step);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 2 * 50, 0);
	mlx_string_put(data->mlx, data->mlx_win, 25, 25, c, str);
	free(str);
	free(step);
	return (0);
}

int	win_close(t_data *data)
{
	ft_free_struct(data);
	exit(0);
	return (0);
}

int	key_catch(int keycode, t_data *data)
{
	int		ret;

	ret = 0;
	if (data->step == 0)
		ft_printf("step count = %d\n", data->step);
	if (keycode == 65307)
		ret = win_close(data);
	else if (keycode == 65362 || keycode == 119)
		ret = ft_move_u(data);
	else if (keycode == 65361 || keycode == 97)
		ret = ft_move_l(data);
	else if (keycode == 65364 || keycode == 115)
		ret = ft_move_d(data);
	else if (keycode == 65363 || keycode == 100)
		ret = ft_move_r(data);
	return (ret);
}

int	ft_hook(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_catch, data);
	mlx_hook(data->mlx_win, 33, 1L << 17, win_close, data);
	return (0);
}
