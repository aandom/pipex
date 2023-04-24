/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:44:38 by aandom            #+#    #+#             */
/*   Updated: 2023/01/15 23:44:38 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(t_lnlist *ln_lst)
{
	int			i;
	t_lnlist	*last_node;

	if (ln_lst == NULL)
		return (0);
	last_node = get_last_node(ln_lst);
	i = 0;
	while (last_node->content[i])
	{
		if (last_node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_lnlist	*get_last_node(t_lnlist *ln_lst)
{
	t_lnlist	*last_node;

	last_node = ln_lst;
	while (last_node)
	{
		if (!last_node->next)
			break ;
		last_node = last_node->next;
	}
	return (last_node);
}

void	create_line(char **line, t_lnlist *ln_lst)
{
	int	i;
	int	slen;

	slen = 0;
	while (ln_lst)
	{
		i = 0;
		while (ln_lst->content[i])
		{
			if (ln_lst->content[i] == '\n')
			{
				slen++;
				break ;
			}
			slen++;
			i++;
		}
		ln_lst = ln_lst->next;
	}
	*line = malloc(sizeof(char) * (slen + 1));
}

void	free_ln_list(t_lnlist *ln_lst)
{
	t_lnlist	*next_node;
	t_lnlist	*cur_node;

	cur_node = ln_lst;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node->content);
		free(cur_node);
		cur_node = next_node;
	}
}
