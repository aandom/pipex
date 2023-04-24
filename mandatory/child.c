/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:25:02 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 17:13:19 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	first_child(t_pipe *pdata, char **av, char **env_p)
{
	char	**cmdpar;
	char	*cmd;

	dup2(pdata->tube[1], 1);
	dup2(pdata->fd_in, 0);
	close(pdata->tube[0]);
	cmdpar = ft_split(av[2], ' ');
	if (!cmdpar)
		empty_cmd(pdata);
	is_dir(cmdpar[0], pdata);
	if (!ft_strchr(cmdpar[0], '/'))
		cmd = extract_cmd(cmdpar[0], pdata);
	else
		check_dir(pdata, &cmd, cmdpar);
	if (!cmd)
		exit(clean_cmd_n_found(pdata, cmdpar));
	if (execve(cmd, cmdpar, env_p) == -1)
	{
		perror(cmdpar[0]);
		exit(execve_error(cmd, cmdpar, pdata));
	}
	free(cmd);
	clean(cmdpar);
}

void	second_child(t_pipe *pdata, char **av, char **env_p)
{
	char	**cmdpar;
	char	*cmd;

	dup2(pdata->tube[0], 0);
	dup2(pdata->fd_out, 1);
	close(pdata->tube[1]);
	cmdpar = ft_split(av[3], ' ');
	if (!cmdpar)
		empty_cmd(pdata);
	is_dir(cmdpar[0], pdata);
	if (!ft_strchr(cmdpar[0], '/'))
		cmd = extract_cmd(cmdpar[0], pdata);
	else
		check_dir(pdata, &cmd, cmdpar);
	if (!cmd)
		exit(clean_cmd_n_found(pdata, cmdpar));
	if (execve(cmd, cmdpar, env_p) == -1)
	{
		perror(cmdpar[0]);
		exit(execve_error(cmd, cmdpar, pdata));
	}
	free(cmd);
	clean(cmdpar);
}
