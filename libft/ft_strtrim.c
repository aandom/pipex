/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:40:41 by aandom            #+#    #+#             */
/*   Updated: 2022/12/22 10:40:41 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	lstart;
	int	lend;

	if (!s1 || !set)
		return (NULL);
	lstart = 0;
	lend = ft_strlen((char *)s1) - 1;
	while ((lstart <= lend) && ft_strchr(set, s1[lstart]))
	{
		lstart++;
	}
	if (lstart >= lend)
		return (ft_strdup(""));
	while (lend > 0 && ft_strchr(set, s1[lend]))
	{
		lend--;
	}
	return (ft_substr(s1, lstart, lend - lstart + 1));
}
