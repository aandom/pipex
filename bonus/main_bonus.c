/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:58:02 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 12:03:55 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipes(t_pipe *pdata)
{
	int	i;

	i = 0;
	while (i < pdata->cmd_num - 1)
	{
		if (pipe(pdata->p_arr + (2 * i)) < 0)
		{
			free(pdata->p_arr);
			free(pdata);
			write(2, "Error on creating pipes...\n", 27);
			exit(0);
		}
		i++;
	}
}

void	pipex(t_pipe *pdata, int ac, char **av, char **env_p)
{
	pdata->cmd_num = ac - 3 - pdata->here_doc;
	pdata->pipe_num = 2 * (pdata->cmd_num - 1);
	pdata->p_arr = malloc(sizeof(int) * (pdata->pipe_num));
	pdata->code = 1;
	create_pipes(pdata);
	pdata->path = get_path(env_p);
	pdata->c_paths = ft_split(pdata->path, ':');
	pdata->p_index = -1;
	while (++(pdata->p_index) < pdata->cmd_num)
		child(pdata, av, env_p);
	close_pipes(pdata);
	waitpid(-1, NULL, 0);
	close_clean_pipe(&pdata);
	free(pdata);
	return ;
}

void	pipex2(t_pipe *pdata, int ac, char **av)
{
	int	x;

	pdata->cmd_num = ac - 3 - pdata->here_doc;
	pdata->pipe_num = 2 * (pdata->cmd_num - 1);
	pdata->p_arr = malloc(sizeof(int) * (pdata->pipe_num));
	pdata->code = 2;
	create_pipes(pdata);
	pdata->p_index = -1;
	while (++(pdata->p_index) < pdata->cmd_num)
		child(pdata, av, NULL);
	close_pipes(pdata);
	x = -1;
	while (++x < pdata->cmd_num)
		waitpid(-1, NULL, 0);
	close_clean_pipe(&pdata);
	free(pdata);
	return ;
}

void	ft_open_outfile(int ac, char **av, t_pipe *pdata)
{
	if (pdata->here_doc == 1)
		pdata->fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		pdata->fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
}

int	main(int ac, char **av, char **env_p)
{
	t_pipe	*pdata;

	if (ac < valid_n_argument(ac, av))
		return (ft_printf("Invalid number of Arguments...\n"));
	pdata = malloc(sizeof(t_pipe));
	set_here_doc(av, pdata);
	if (pdata->here_doc == 0)
		pdata->fd_in = open(av[1], O_RDONLY);
	else
	{
		here_doc(av);
		pdata->fd_in = open(".here_doc", O_RDONLY);
	}
	if (pdata->fd_in < 0)
		perror(av[1]);
	ft_open_outfile(ac, av, pdata);
	if (pdata->fd_out < 0)
		exit(ft_exit(pdata, 2, av[ac - 1]));
	if (!get_path(env_p))
		pipex2(pdata, ac, av);
	else
		pipex(pdata, ac, av, env_p);
	return (0);
}
