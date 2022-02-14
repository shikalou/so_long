/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/14 18:09:07 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int	main()
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1000, 1200);
	mlx_loop(mlx);
}
*/

t_data	*new_data(int i, char *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->map = ft_malloctab(i, map);
	data->max_liney = i;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1500, 1100, "test");
	data->mlx_img = mlx_new_image(data->mlx, );
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

	mlx_loop(data->mlx);
}
