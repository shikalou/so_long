/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/24 20:38:17 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap2(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->max_liney)
	{
		x = -1;
		while (++x < data->len_linex)
		{
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
					x * 50, y * 50);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->rupee2,
					x * 50, y * 50);
			else if (data->map[y][x] == 'B')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->bats,
					x * 50, y * 50);
		}
	}
}

void	ft_printmap(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->max_liney)
	{
		x = -1;
		while (++x < data->len_linex)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
					x * 50, y * 50);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
					x * 50, y * 50);
			else if (data->map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->link_d,
					x * 50, y * 50);
				data->p_x = x;
				data->p_y = y;
			}
		}
	}
	ft_printmap2(data);
}

int	ft_check_arg(char *arg)
{
	int	fd2;

	if (ft_strlen(arg) > 3)
	{
		fd2 = open(arg, __O_DIRECTORY);
		if (fd2 != -1 || !ft_strnstr((arg + (ft_strlen(arg) - 4)), ".ber", 5))
		{
			ft_putstr_fd("Error\nWrong file type\n", 2);
			return (0);
		}
		close(fd2);
		return (1);
	}
	ft_putstr_fd("Error\nWrong files\n", 2);
	return (0);
}


int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_data	*data;
	t_count	*truc;


	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong arguments count\n", 2);
		return (1);
	}
	if (!ft_check_arg(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	truc = malloc(sizeof(t_count));
	i = ft_check_map(fd, truc);
	close(fd);
	if (i == 0)
		return (1);
	data = init_data(i, argv[1], truc);
	free(truc);
	ft_printmap(data);
	ft_hook(data);
	mlx_loop_hook(data->mlx, string_put, data);
	mlx_loop(data->mlx);
	//ft_free_struct(data);
}
