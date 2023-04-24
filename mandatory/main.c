/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:41:13 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 11:13:52 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	no_file_or_directory(int ac, char **av)
{
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		write(2, "bash: ", 7);
		write(2, av[i], ft_strlen(av[i]));
		write(2, ": No such file or directory\n", 29);
		i++;
	}
	return (127);
}

void	pipex(t_pipe *pdata, char **av, char **env_p)
{
	pdata->code = 1;
	pdata->path = get_path(env_p);
	pdata->c_paths = ft_split(pdata->path, ':');
	pipe(pdata->tube);
	if (pdata->fd_in != -1)
		pdata->pid1 = fork();
	if (pdata->pid1 < 0)
		exit(fork_error(pdata));
	if (pdata->pid1 == 0 && pdata->fd_in != -1)
		first_child(pdata, av, env_p);
	pdata->pid2 = fork();
	if (pdata->pid2 < 0)
		exit(fork_error(pdata));
	if (pdata->pid2 == 0)
		second_child(pdata, av, env_p);
	close_clean_pipe(&pdata);
	if (pdata->fd_in != -1)
		waitpid(pdata->pid1, NULL, 0);
	waitpid(pdata->pid2, NULL, 0);
	free(pdata);
	return ;
}

void	pipex2(t_pipe *pdata, char **av)
{
	pipe(pdata->tube);
	pdata->code = 2;
	if (pdata->fd_in != -1)
		pdata->pid1 = fork();
	if (pdata->pid1 < 0)
		exit(fork_error(pdata));
	if (pdata->pid1 == 0 && pdata->fd_in != -1)
		first_child(pdata, av, NULL);
	pdata->pid2 = fork();
	if (pdata->pid2 < 0)
		exit(fork_error(pdata));
	if (pdata->pid2 == 0)
		second_child(pdata, av, NULL);
	close_clean_pipe(&pdata);
	if (pdata->fd_in != -1)
		waitpid(pdata->pid1, NULL, 0);
	waitpid(pdata->pid2, NULL, 0);
	free(pdata);
	return ;
}

static int	ft_exit(t_pipe *pdata)
{
	free(pdata);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env_p)
{
	t_pipe	*pdata;

	if (ac != 5)
		return (ft_printf("Invalid number of Arguments...\n"));
	pdata = malloc(sizeof(t_pipe));
	pdata->fd_in = open(av[1], O_RDONLY);
	if (pdata->fd_in < 0)
		perror(av[1]);
	pdata->fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pdata->fd_out < 0)
	{
		perror(av[ac - 1]);
		exit(ft_exit(pdata));
	}
	pdata->pid1 = 0;
	pdata->pid2 = 0;
	if (!get_path(env_p))
		pipex2(pdata, av);
	else
		pipex(pdata, av, env_p);
	return (0);
}
