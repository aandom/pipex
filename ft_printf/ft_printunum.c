/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:25:17 by aandom            #+#    #+#             */
/*   Updated: 2023/01/09 19:18:29 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(unsigned int num)
{
	size_t	nsize;

	nsize = 0;
	while (num != 0)
	{
		num = num / 10;
		nsize++;
	}
	return (nsize);
}

char	*ft_unumtostr(unsigned int num)
{
	char	*str;
	int		i;

	i = ft_numlen(num);
	str = (char *) malloc (sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (num != 0)
	{
		str[i - 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}

int	ft_printunum(unsigned int num)
{
	int		count;
	char	*s;

	count = 0;
	if (num == 0)
		return (ft_printchar('0'));
	s = ft_unumtostr(num);
	count = ft_printstr(s);
	free(s);
	return (count);
}
