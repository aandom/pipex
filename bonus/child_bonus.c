/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:34:06 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 19:46:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void	file_permission(char *cmd, t_pipe *pdata)
// {
// 	if (access(cmd, F_OK) != 0)
// 		exit(check_permission(pdata, 1));
// 	if (access(cmd, X_OK) != 0)
// 		exit(check_permission(pdata, 2));
// }

static void	duplicate_fds(int read_end, int write_end)
{
	dup2(read_end, 0);
	dup2(write_end, 1);
}

static void	ft_dup_fds(t_pipe *pdata)
{
	if (pdata->p_index == 0)
		duplicate_fds(pdata->fd_in, pdata->p_arr[1]);
	else if (pdata->p_index == pdata->cmd_num - 1)
		duplicate_fds(pdata->p_arr[2 * pdata->p_index - 2], pdata->fd_out);
	else
		duplicate_fds(pdata->p_arr[2 * pdata->p_index - 2], \
		pdata->p_arr[2 * pdata->p_index + 1]);
	close_pipes(pdata);
}

void	execute_command(char *cmd, char **cmdpar, char **env_p, t_pipe *pdata)
{
	if (execve(cmd, cmdpar, env_p) == -1)
	{
		perror(cmdpar[0]);
		exit(execve_error(cmd, cmdpar, pdata));
	}
}

void	child(t_pipe *pdata, char **av, char **env_p)
{
	pid_t	pid;
	char	**cmdpar;
	char	*cmd;

	pid = fork();
	if (pid < 0)
		exit(fork_error(pdata));
	if (pid == 0)
	{
		ft_dup_fds(pdata);
		cmdpar = ft_split(av[2 + pdata->here_doc + pdata->p_index], ' ');
		if (!cmdpar)
			empty_cmd(pdata);
		is_dir(cmdpar[0], pdata);
		if (!ft_strchr(cmdpar[0], '/'))
			cmd = extract_cmd(cmdpar[0], pdata);
		else
			check_dir(pdata, &cmd, cmdpar);
		if (!cmd)
			exit(clean_cmd_n_found(pdata, cmd, cmdpar));
		execute_command(cmd, cmdpar, env_p, pdata);
		free(cmd);
		clean(cmdpar);
	}
}
