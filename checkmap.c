/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:21 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/09 16:31:24 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkstr1(char *str, int i)
{

}

int	ft_check_map(int fd)
{
	char 	**tab;
	char 	*str;
	int	i;

	i = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		i++;
		if (ft_checkstr1(str, i));

	}
	tab = malloc(sizeof(char *) * (i + 1));
}
