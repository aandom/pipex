/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:47:34 by aandom            #+#    #+#             */
/*   Updated: 2023/01/09 19:49:58 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	numbersize(long n)
{
	size_t	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	while (1)
	{
		n = n / 10;
		i++;
		if (n == 0)
			break ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*s;
	size_t	nsize;

	num = n;
	nsize = numbersize(n);
	s = (char *) malloc (sizeof(char) * (nsize + 1));
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		num = num * -1;
	}
	s [nsize] = '\0';
	while (1)
	{
		s[nsize - 1] = (num % 10) + '0';
		num /= 10;
		nsize--;
		if (num == 0)
			break ;
	}
	return (s);
}
