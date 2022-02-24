/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:21 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/24 15:34:57 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isvalid(char c, char *toto, int pec[4], t_count *truc)
{
	int	i;

	i = 0;
	while (toto[i])
	{
		if (toto[i] == c)
		{
			if (c == 'P')
				pec[0]++;
			if (c == 'E')
				pec[1]++;
			if (c == 'C')
			{
				pec[2]++;
				truc->total = pec[2];
			}
			if (c == '1')
				pec[3]++;
			return (1);
		}
		i++;
	}
	ft_putstr_fd("Error\nMap's norme check fail\n", 2);
	return (0);
}

int	ft_check_str(char *str, int pec[4], size_t len, t_count *truc)
{
	int	j;
	int	p;

	j = 0;
	p = 0;
	if (!str)
		return (1);
	pec[3] = 0;
	if (len != ft_strlen(str) && (len - 1) != ft_strlen(str))
	{
		ft_putstr_fd("Error\nWalls' norme check fail\n", 2);
		return (0);
	}
	if (!(str[j] == '1' && str[len - 2] == '1'))
	{
		ft_putstr_fd("Error\nWalls' norme check fail\n", 2);
		return (0);
	}
	while (str[j] && str[j] != '\n')
	{
		if (!ft_isvalid(str[j], TOTO, pec, truc))
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_first(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		return (0);
	}
	while (str[i] != '\n')
	{
		if (str[i] != '1')
		{
			ft_putstr_fd("Error\nWalls' norme check fail\n", 2);
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_pec(int pec[4], int len)
{
	if (pec[0] != 1)
	{
		ft_putstr_fd("Error\nWrong starting point count\n", 2);
		return (0);
	}
	else if (pec[1] < 1)
	{
		ft_putstr_fd("Error\nWrong exit point count\n", 2);
		return (0);
	}
	else if (pec[2] < 1)
	{
		ft_putstr_fd("Error\nNo collectible\n", 2);
		return (0);
	}
	else if (pec[3] != (len - 1))
	{
		ft_putstr_fd("Error\nWalls' norme check fail\n", 2);
		return (0);
	}
	else
		return (1);
}

int	ft_check_map(int fd, t_count *truc)
{
	char	*str;
	int		i;
	size_t	len;
	int		pec[4];

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
		if (!ft_check_str(str, pec, len, truc))
		{
			free(str);
			return (0);
		}
		i++;
	}
	if (!ft_check_pec(pec, len))
		return (0);
	return (i);
}
