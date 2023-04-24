/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:33:11 by aandom            #+#    #+#             */
/*   Updated: 2023/01/05 17:33:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnum(int n)
{
	char	*str;
	int		c;

	c = 0;
	str = ft_itoa(n);
	c = ft_printstr(str);
	free(str);
	return (c);
}
