/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:12:19 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 17:04:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while ((env + i) && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			str = env[i] + 5;
			return (str);
		}
		i++;
	}
	if (!str)
		return (NULL);
	return (str);
}

char	*extract_cmd(char *cpar, t_pipe *pdata)
{
	char	*cmd;
	char	*tmp;
	int		i;

	i = 0;
	if (!pdata->c_paths)
		return (ft_strdup(cpar));
	while (pdata->c_paths[i] != NULL)
	{
		if (pdata->c_paths[i][ft_strlen(pdata->c_paths[i]) - 1] != '/')
			tmp = ft_strjoin(pdata->c_paths[i], "/");
		else
			tmp = ft_strdup(pdata->c_paths[i]);
		cmd = ft_strjoin(tmp, cpar);
		free(tmp);
		if (access(cmd, 0) == 0)
		{
			return (cmd);
		}
		free(cmd);
		i++;
	}
	return (NULL);
}

void	empty_cmd(t_pipe *pdata)
{
	close_clean_pipe(&pdata);
	free(pdata);
	cmd_not_found(": ");
	exit(0);
}

int	permission_denied(const char *str)
{
	write(2, "bash: ", 7);
	write(2, str, ft_strlen(str));
	write(2, ": Permission denied\n", 21);
	return (126);
}
