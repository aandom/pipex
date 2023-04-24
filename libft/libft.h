/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:18:36 by aandom            #+#    #+#             */
/*   Updated: 2023/04/17 21:48:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
// # include "../ft_printf/ft_printf.h"

typedef struct s_array
{
	int		*arr;
	int		arr_max;
	int		arr_min;
	int		med;
	int		len;
}			t_array;

char	**ft_split(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**clean(char **av);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_strcmp(char *str1, char *str2);
char	**no_split(char *str, int c);

#endif