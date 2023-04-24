/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:02:25 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 12:57:55 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	return ;
}

int	clean_cmd_n_found(t_pipe *pdata, char **cmdpar)
{
	cmd_not_found(cmdpar[0]);
	close_clean_pipe(&pdata);
	free(pdata);
	clean(cmdpar);
	return (127);
}

int	check_permission(t_pipe *pdata, int code)
{
	if (code == 1)
		write(2, "No such file or diectory: \n", 28);
	else if (code == 2)
		write(2, "Permission denied: \n", 21);
	close_clean_pipe(&pdata);
	free(pdata);
	return (126);
}

int	fork_error(t_pipe *pdata)
{
	close_clean_pipe(&pdata);
	free(pdata);
	write(2, "Error While Forking...\n", 23);
	return (-1);
}

int	execve_error(char *cmd, char **cmdpar, t_pipe *pdata)
{
	free(cmd);
	clean(cmdpar);
	return (check_permission(pdata, 3));
}
