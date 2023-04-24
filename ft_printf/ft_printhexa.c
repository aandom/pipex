/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:35:08 by aandom            #+#    #+#             */
/*   Updated: 2023/01/04 22:35:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writehexa(unsigned int p, const char c)
{
	if (p >= 16)
	{
		ft_writehexa(p / 16, c);
		ft_writehexa(p % 16, c);
	}
	else if (p > 9)
	{
		if (c == 'x')
			ft_printchar(p - 10 + 'a');
		else
			ft_printchar(p - 10 + 'A');
	}
	else
		ft_printchar(p + '0');
}

int	ft_countchar2(unsigned int p)
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

int	ft_printhexa(unsigned int p, const char c)
{
	int	count;

	count = 0;
	if (p == 0)
		count = count + write(1, "0", 1);
	else
		ft_writehexa(p, c);
	count = count + ft_countchar2(p);
	return (count);
}
