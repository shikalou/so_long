/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:25:25 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/14 17:24:23 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}*/

void    ft_putstr_fd(char *s, int fd)
{
    int    i;

    if (!s)
        return ;
    i = 0;
    while (*(s + i))
        i++;
    if (fd == 2)
        write(2, "\e[1;31m", 7);
    write(fd, s, i);
    if (fd == 2)
        write(2, "\e[0m", 7);
}
