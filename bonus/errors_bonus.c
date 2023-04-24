/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:02:25 by aandom            #+#    #+#             */
/*   Updated: 2023/04/18 20:37:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	empty_cmd(t_pipe *pdata)
{
	close_clean_pipe(&pdata);
	free(pdata);
	cmd_not_found(": ");
	exit(0);
}

void	cmd_not_found(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	return ;
}

int	clean_cmd_n_found(t_pipe *pdata, char *cmd, char **cmdpar)
{
	cmd_not_found(cmdpar[0]);
	close_clean_pipe(&pdata);
	free(pdata);
	free(cmd);
	clean(cmdpar);
	return (127);
}

int	check_permission(t_pipe *pdata, int code)
{
	if (code == 1)
		write(2, "No such file or diectory: \n", 28);
	else if (code == 2)
		write(2, "Permission denied\n", 21);
	close_clean_pipe(&pdata);
	free(pdata);
	exit(126);
}

int	fork_error(t_pipe *pdata)
{
	close_clean_pipe(&pdata);
	free(pdata);
	write(2, "Error While Forking...\n", 23);
	return (-1);
}
