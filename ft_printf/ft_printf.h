/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:54:15 by aandom            #+#    #+#             */
/*   Updated: 2023/01/04 11:54:15 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_printhex(unsigned int n);
int		ft_printptr(unsigned long long p);
int		ft_printnum(int n);
int		ft_printhexa(unsigned int p, const char c);
int		ft_printstr(char *str);
int		ft_printchar(int c);
int		ft_printunum(unsigned int num);
char	*ft_itoa(int n);

#endif