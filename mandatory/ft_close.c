/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:22:00 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 12:28:44 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_clean_pipe(t_pipe **pipe)
{
	close((*pipe)->tube[0]);
	close((*pipe)->tube[1]);
	if ((*pipe)->fd_in < 0 && (*pipe)->pid1 > 0)
		close((*pipe)->fd_in);
	if ((*pipe)->fd_out < 0 && (*pipe)->pid2 > 0)
		close((*pipe)->fd_out);
	if ((*pipe)->code == 1)
		clean((*pipe)->c_paths);
}
