/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:21 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/09 16:57:38 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkstr1(char *str, int i)
{
	int	j;

	j = 0;
	if (str[j] == '1')
	{
	}
}

int	ft_check_map(int fd)
{
	char 	**tab;
	char 	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = get_next_line(fd);
	while (str[j])
	{
		if (str[j] == '1')
			j++;
		else
		{
			ft_putstr_fd("Error\nMap  pas a la norme\n", 1);
			return (0);
		}

	}
	while (str != NULL)
	{
		i++;
		if (ft_checkstr1(str, i))
			return (1);
		str = get_next_line(fd);

	}
	tab = malloc(sizeof(char *) * (i + 1));
}
