/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:22:00 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 21:40:37 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_num))
	{
		close(pipex->p_arr[i]);
		i++;
	}
}

void	close_clean_pipe(t_pipe **pipe)
{
	close_pipes(*pipe);
	if ((*pipe)->fd_in != -1)
		close((*pipe)->fd_in);
	if ((*pipe)->fd_in != -1)
		close((*pipe)->fd_out);
	free((*pipe)->p_arr);
	if ((*pipe)->code == 1)
		clean((*pipe)->c_paths);
}

void	check_dir(t_pipe *pdata, char **cmd, char **cmdpar)
{
	*cmd = ft_strdup(cmdpar[0]);
	if ((*cmd)[ft_strlen(*cmd) - 1] == '/' && access(*cmd, 0) == 0)
	{
		write(2, ": ", 2);
		write(1, *cmd, ft_strlen(*cmd));
		write(2, ": is a directory\n", 18);
		close_clean_pipe(&pdata);
		clean(cmdpar);
		free(pdata);
		free(cmd);
		exit(0);
	}
}

void	is_dir(char *str, t_pipe *pdata)
{
	if (ft_strcmp(str, "/"))
		return ;
	else
	{
		close_clean_pipe(&pdata);
		free(pdata);
		write(2, " /: Is a directory\n", 19);
		exit(0);
	}
}
