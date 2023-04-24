/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:25:23 by aandom            #+#    #+#             */
/*   Updated: 2023/01/04 22:25:23 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writehex(unsigned long long p)
{
	if (p >= 16)
	{
		ft_writehex(p / 16);
		ft_writehex(p % 16);
	}
	else if (p > 9)
		ft_printchar(p - 10 + 'a');
	else
		ft_printchar(p + '0');
}

int	ft_countchar(unsigned long long p)
{
	int	count;

	count = 0;
	while (p != 0)
	{
		count++;
		p = p / 16;
	}
	return (count);
}

int	ft_printptr(unsigned long long p)
{
	int	c;

	c = 0;
	c = c + write(1, "0x", 2);
	if (p == 0)
		c = c + write(1, "0", 1);
	else
	{
		ft_writehex(p);
	}
	c = c + ft_countchar(p);
	return (c);
}
