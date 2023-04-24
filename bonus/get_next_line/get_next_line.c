/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:20:53 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 13:00:04 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_lnlist	*ln_list;
	char			*readed_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX \
	|| (read(fd, 0, 0) < 0))
		return (NULL);
	read_to_ln_list(fd, &ln_list);
	if (ln_list == NULL)
		return (NULL);
	copy_to_line(ln_list, &readed_line);
	if (readed_line[0] == '\0')
	{
		free_ln_list(ln_list);
		ln_list = NULL;
		free(readed_line);
		return (NULL);
	}
	free_ln_list(ln_list);
	ln_list = NULL;
	return (readed_line);
}

void	read_to_ln_list(int fd, t_lnlist **ln_list)
{
	char	*buff;
	int		readed_chars;

	readed_chars = 1;
	while (!check_newline(*ln_list) && readed_chars != 0)
	{
		buff = malloc(sizeof(char) * (((size_t) BUFFER_SIZE) + 1));
		if (!buff)
			return ;
		readed_chars = (int) read (fd, buff, BUFFER_SIZE);
		if ((*ln_list == NULL && readed_chars == 0) || readed_chars == -1)
		{
			free (buff);
			return ;
		}
		buff[readed_chars] = '\0';
		add_node_ln_lst(ln_list, buff, readed_chars);
		free(buff);
	}
}

void	add_node_ln_lst(t_lnlist **ln_list, char *buff, int readed_chars)
{
	int			i;
	t_lnlist	*newnode;
	t_lnlist	*last;

	newnode = malloc(sizeof(t_lnlist));
	if (!newnode)
		return ;
	newnode->next = NULL;
	newnode->content = malloc(sizeof(char) * (readed_chars + 1));
	if (!newnode->content)
		return ;
	i = 0;
	while (buff[i] && i < readed_chars)
	{
		newnode->content[i] = buff[i];
		i++;
	}
	newnode->content[i] = '\0';
	if (*ln_list == NULL)
	{
		*ln_list = newnode;
		return ;
	}
	last = get_last_node(*ln_list);
	last->next = newnode;
}

void	copy_to_line(t_lnlist *ln_list, char **line)
{
	int	i;
	int	m;

	if (!ln_list)
		return ;
	create_line (line, ln_list);
	if (!(*line))
		return ;
	m = 0;
	while (ln_list)
	{
		i = 0;
		while (ln_list->content[i])
		{
			if (ln_list->content[i] == '\n')
			{
				(*line)[m++] = ln_list->content[i];
				break ;
			}
			(*line)[m++] = ln_list->content[i++];
		}
		ln_list = ln_list->next;
	}
	(*line)[m] = '\0';
}
