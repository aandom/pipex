/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:53:47 by aandom            #+#    #+#             */
/*   Updated: 2023/01/04 11:53:47 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_checkflag(va_list ar, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(ar, int));
	else if (c == 's')
		count += ft_printstr(va_arg(ar, char *));
	else if (c == 'p')
		count += ft_printptr(va_arg(ar, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_printnum(va_arg(ar, int));
	else if (c == 'u')
		count += ft_printunum(va_arg(ar, unsigned int));
	else if (c == 'X' || c == 'x')
		count = ft_printhexa(va_arg(ar, unsigned int), c);
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	myargs;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(myargs, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = count + ft_checkflag(myargs, s[i + 1]);
			i++;
		}
		else
		{
			count = count + ft_printchar(s[i]);
		}
		i++;
	}
	va_end(myargs);
	return (count);
}
