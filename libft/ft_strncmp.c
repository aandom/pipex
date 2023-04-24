/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:38:43 by aandom            #+#    #+#             */
/*   Updated: 2023/04/15 11:24:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != 0 && str2[i] != 0) && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((int) str1[i] - str2[i]);
	}
	if (i != n)
	{
		return ((int) str1[i] - str2[i]);
	}
	return ((int) str1[i - 1] - str2[i - 1]);
}
