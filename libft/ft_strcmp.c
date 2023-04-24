/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:19:41 by aandom            #+#    #+#             */
/*   Updated: 2023/04/17 21:44:57 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (1);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	if ((!*str1 && !*str2))
		return (0);
	return (1);
}
