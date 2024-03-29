/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:01:49 by ldinaut           #+#    #+#             */
/*   Updated: 2021/12/09 15:06:19 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnb(int n)
{
	int					i;
	unsigned int		nb;

	nb = n;
	i = 1;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
