/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/28 14:08:24 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(int argc, char *arg)
{
	int	fd2;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong arguments count \n", 2);
		return (0);
	}
	if (ft_strlen(arg) > 3)
	{
		fd2 = open(arg, __O_DIRECTORY);
		if (fd2 != -1 || !ft_strnstr((arg + (ft_strlen(arg) - 4)), ".ber", 5))
		{
			close(fd2);
			ft_putstr_fd("Error\nWrong file type\n", 2);
			return (0);
		}
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
	int		truc;

	if (!ft_check_arg(argc, argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("\e[1;31mError\nopen");
		write(2, "\e[0m", 4);
		return (1);
	}
	i = ft_check_map(fd, &truc);
	if (i == 0)
		return (1);
	close(fd);
	data = init_data(i, argv[1], truc);
	ft_printmap(data);
	ft_hook(data);
	mlx_loop_hook(data->mlx, string_put, data);
	mlx_loop(data->mlx);
}
