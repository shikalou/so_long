/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:24 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/11 01:32:40 by macbook          ###   ########.fr       */
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
# include <stdlib.h>

int	ft_check_map(int fd);
int	ft_checkstr(char *str, int pec[4], size_t len);
int	ft_isvalid(char c, char *toto, int pec[4]);
int	ft_check_first(char *str);

char	*get_next_line(int fd);

#endif
