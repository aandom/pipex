/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:05:25 by aandom            #+#    #+#             */
/*   Updated: 2023/03/31 13:05:25 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**no_split(char *str, int c)
{
	char	**strings;

	if (c == 0)
		return (0);
	strings = malloc(sizeof(char *) * 2);
	if (!strings)
		return (0);
	strings[0] = ft_strdup(str);
	strings[1] = 0;
	return (strings);
}
