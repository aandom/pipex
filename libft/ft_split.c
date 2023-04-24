/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:00:49 by aandom            #+#    #+#             */
/*   Updated: 2022/12/23 11:00:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**clean(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (0);
}

int	count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_word(const char *str, char c)
{
	int		size;
	int		i;
	char	*word;

	i = 0;
	size = 0;
	while (str[size] && str[size] != c)
		size++;
	word = (char *) malloc(sizeof(char) * (size + 1));
	if (!word)
		return (0);
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*jump_chars(char *str, int c, int code)
{
	if (code == 1)
	{
		while (*str != '\0' && *str == c)
			str++;
	}
	else if (code == 2)
	{
		while (*str && *str != c)
			str++;
	}
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**strings;
	int		i;

	if (!str || *str == 0)
		return (0);
	i = 0;
	if (count_strings(str, c) <= 1)
		return (no_split(str, c));
	strings = (char **) malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (0);
	while (*str != '\0')
	{
		str = jump_chars(str, c, 1);
		if (*str != '\0')
		{
			strings[i] = ft_word(str, c);
			if (strings[i] == NULL)
				return (clean(strings));
			i++;
		}
		str = jump_chars(str, c, 2);
	}
	strings[i] = 0;
	return (strings);
}
