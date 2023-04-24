/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:21:17 by aandom            #+#    #+#             */
/*   Updated: 2023/01/04 22:21:17 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	c;

	c = 0;
	if (!str)
	{
		return (ft_printstr("(null)"));
	}
	else
	{
		while (str[c])
		{
			ft_printchar(str[c]);
			c++;
		}
	}
	return (c);
}
