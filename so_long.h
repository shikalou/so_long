/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:24 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/15 17:35:27 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TOTO "10PEC"

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	void	*floor;
	void	*wall;
	void	*link_d;
	void	*link_r;
	void	*link_u;
	void	*link_l;
	void	*exit;
	int		len_linex;
	int		max_liney;
	char	**map;
}	t_data;

int		ft_checkarg(char *arg);
int		ft_check_map(int fd);
int		ft_checkstr(char *str, int pec[4], size_t len);
int		ft_isvalid(char c, char *toto, int pec[4]);
int		ft_check_first(char *str);

char	*get_next_line(int fd);
char	**ft_malloctab(int i, char *map);

void	ft_free(char **tab, int j);

#endif
