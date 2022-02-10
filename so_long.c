/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/10 17:02:39 by ldinaut          ###   ########.fr       */
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
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);
}
*/

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (!ft_check_map(fd))
		{
			ft_putstr_fd("Error\nMap's norme check fail\n", 2);
			return (0);
		}
		printf("un genie ce louis\n");
	}
	else
	{
		ft_putstr_fd("Error\nToo few arguments\n", 2);
		return (0);
	}
}
