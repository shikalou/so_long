/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:24 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/24 20:12:34 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TOTO "10PECB"

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_count
{
	int	total;
}	t_count;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	void	*floor;
	void	*wall;
	void	*link_d;
	void	*link_r;
	void	*link_u;
	void	*link_l;
	void	*exit;
	void	*rupee;
	void	*rupee2;
	void	*bats;

	int		step;
	int		len_linex;
	int		max_liney;
	int		p_y;
	int		p_x;
	int		rupee_count;

	char	**map;
}	t_data;

t_data	*init_data(int i, char *map, t_count *truc);

int		ft_check_arg(char *arg);
int		ft_check_map(int fd, t_count *truc);
int		ft_check_str(char *str, int pec[4], size_t len, t_count *truc);
int		ft_isvalid(char c, char *toto, int pec[4], t_count *truc);
int		ft_check_first(char *str);
int		ft_check_pec(int pec[4], int len);
int		ft_hook(t_data *data);
int		key_catch(int keycode, t_data *data);
int		win_close(t_data *data);
int		ft_move_d(t_data *data);
int		ft_move_u(t_data *data);
int		ft_move_r(t_data *data);
int		ft_move_l(t_data *data);
int		string_put(t_data *data);


char	*get_next_line(int fd);
char	**ft_malloctab(int i, char *map);

void	ft_free(char **tab, int j);
void	ft_printmap(t_data *data);
void	ft_put_u(t_data *data);
void	ft_put_r(t_data *data);
void	ft_put_l(t_data *data);
void	ft_put_d(t_data *data);
void	ft_collec_rupee_d(t_data *data);
void	ft_collec_rupee_u(t_data *data);
void	ft_collec_rupee_r(t_data *data);
void	ft_collec_rupee_l(t_data *data);
void	ft_loose(t_data *data);
void	init_img(t_data *data);
void	ft_check_size(int x, int y);
void	ft_free_struct(t_data *data);

#endif
