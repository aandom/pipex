/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:48:31 by aandom            #+#    #+#             */
/*   Updated: 2023/01/20 02:48:31 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_lnlist
{
	char			*content;
	struct s_lnlist	*next;
}					t_lnlist;

char		*get_next_line(int fd);
void		read_to_ln_list(int fd, t_lnlist **ln_list);
void		add_node_ln_lst(t_lnlist **ln_list, char *buff, int readed_chars);
void		copy_to_line(t_lnlist *ln_list, char **line);
void		clean_ln_list(t_lnlist **ln_list);
int			check_newline(t_lnlist *ln_lst);
t_lnlist	*get_last_node(t_lnlist *ln_lst);
void		create_line(char **line, t_lnlist *ln_lst);
void		free_ln_list(t_lnlist *ln_lst);

#endif