/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:55:17 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 12:04:09 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_here_doc(char *str)
{
	char	*res;
	int		c;

	c = 0;
	res = ft_strtrim(str, " \t");
	if (!ft_strcmp(res, "here_doc"))
		c = 1;
	free(res);
	return (c);
}

void	set_here_doc(char **str, t_pipe *pdata)
{
	if (is_here_doc(str[1]))
	{
		pdata->here_doc = 1;
		pdata->cmd_index = 3;
	}
	else
	{
		pdata->here_doc = 0;
		pdata->cmd_index = 2;
	}
}

void	here_doc(char **av)
{
	int		fd1;
	char	*line;

	fd1 = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(line, av[2], ft_strlen(av[2])))
			break ;
		else
			write(fd1, line, ft_strlen(line));
		free(line);
	}
	close(fd1);
	free(line);
	return ;
}

int	valid_n_argument(int ac, char **av)
{
	if (ac < 5)
		return (ac + 1);
	if (av[1] == NULL)
		return (0);
	if (is_here_doc(av[1]))
		return (6);
	return (5);
}
