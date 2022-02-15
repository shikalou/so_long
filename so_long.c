/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/15 18:13:54 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->max_liney)
	{
		x = 0;
		while (x < data->len_linex)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall, (x * 50), (y * 50));
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->floor, (x * 50), (y * 50));
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->link_d, (x * 50), (y * 50));
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->exit, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
}

t_data	*new_data(int i, char *map)
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
			(data->max_liney * 50), "the legend of Luna");
	data->floor = mlx_xpm_file_to_image(data->mlx, "img/floor2.xpm", &a, &b);
	data->wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &a, &b);
	data->exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm", &a, &b);
	data->link_d = mlx_xpm_file_to_image(data->mlx, "img/link_d.xpm", &a, &b);
	return (data);
}

int	ft_checkarg(char *arg)
{
	int	fd2;

	if (ft_strlen(arg) > 3)
	{
		fd2 = open(arg, __O_DIRECTORY);
		if (fd2 != -1 || !ft_strnstr((arg + (ft_strlen(arg) - 4)), ".ber", 5))
		{
			ft_putstr_fd("Error\nWrong file\n", 2);
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

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong arguments count\n", 2);
		return (1);
	}
	if (!ft_checkarg(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = ft_check_map(fd);
	close(fd);
	if (i == 0)
		return (1);
	data = new_data(i, argv[1]);
	ft_printmap(data);
	mlx_loop(data->mlx);
}
