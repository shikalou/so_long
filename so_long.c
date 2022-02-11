/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/11 17:23:18 by ldinaut          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**tab;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror("open");
		i = ft_check_map(fd);
		close(fd);
		if (i == 0)
			return (0);
		tab = ft_malloctab(i, argv[1]);
	}
	else
	{
		ft_putstr_fd("Error\nWrong arguments count\n", 2);
		return (0);
	}
}
