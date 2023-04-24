/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:11:27 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 10:01:34 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	no_file_or_directory(int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	c = valid_n_argument(ac, av);
	if (c == 5)
		i = 2;
	else
		i = 3;
	printf("i = %d\n", i);
	printf("c = %d\n", c);
	while (i < ac - 1)
	{
		write(2, "bash: ", 7);
		write(2, av[i], ft_strlen(av[i]));
		write(2, ": No such file or directory\n", 29);
		i++;
	}
	return (127);
}

int	ft_exit(t_pipe *pdata, int code, char *file)
{
	if (code == 1)
		(perror("infile:"));
	else
		(perror(file));
	free(pdata);
	return (EXIT_SUCCESS);
}

int	execve_error(char *cmd, char **cmdpar, t_pipe *pdata)
{
	free(cmd);
	clean(cmdpar);
	return (check_permission(pdata, 3));
}
