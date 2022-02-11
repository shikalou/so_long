/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:42 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/11 14:45:38 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_filltab(char **tab, int i, int fd)
{
	char *str;

	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	str = get_next_line(fd);
}