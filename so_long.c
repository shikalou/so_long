/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:54:07 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/11 15:19:03 by ldinaut          ###   ########.fr       */
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
	//char	**tab = NULL;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("open");
	if (argc == 2)
	{
		if (!ft_check_map(fd))
		{
			ft_putstr_fd("Map's norme check fail\n", 2);
			return (0);
		}
		printf("hihi");
		//i = ft_check_map(fd);
		//tab = ft_filltab(tab, i, fd);
	}
	else
	{
		ft_putstr_fd("Wrong arguments count\n", 2);
		return (0);
	}
}
