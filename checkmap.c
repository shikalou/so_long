/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:21 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/10 16:56:38 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isvalid(char c, char *toto, int pec[4])
{
	int	i;

	i = 0;
	while (toto[i])
	{
		if (toto[i] == c)
		{
			if (c == 'P')
				pec[0]++;
			else if (c == 'E')
				pec[1]++;
			else if (c == 'C')
				pec[2]++;
			else if (c == '1')
				pec[3]++;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checkstr(char *str, int pec[4], size_t len)
{
	int	j;
	int	p;

	j = 0;
	p = 0;
	if (len != ft_strlen(str))
		return (0);
	if (!(str[j] == '1' && str[len - 1] == '1'))
			return (0);
	while (str[j])
	{
		if (!ft_isvalid(str[j], TOTO, pec))
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_first(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			i++;
		else
		{
			free(str);
			return (0);
		}
	}
	return (1);
}

int	ft_check_pec(int pec[4], int len)
{
	if (pec[0] != 1)
		return (0);
	else if (pec[1] < 1)
		return (0);
	else if (pec[2] < 1)
		return(0);
	else if (pec[3] != len)
		return (0);
	else
		return (1);
}

int	ft_check_map(int fd)
{
	char 	*str;
	int		i;
	size_t	len;
	int 	pec[4];

	i = 0;
	ft_bzero(pec, 16);
	str = get_next_line(fd);
	len = ft_strlen(str);
	if (!ft_check_first(str))
		return (0);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (!ft_checkstr(str, pec, len))
		{
			free(str);
			return (0);
		}
		i++;
	}
	if (!ft_check_pec(pec, len))
		return (0);
	return (1);
}
