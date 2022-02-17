/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:42 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/17 19:20:02 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_malloctab(int i, char *map)
{
	int		j;
	int		fd;
	char	**tab;

	j = 0;
	fd = open(map, O_RDONLY);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	while (j < i)
	{
		tab[j] = get_next_line(fd);
		if (!tab[j])
			ft_free(tab, j);
		j++;
	}
	return (tab);
}
