/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:41:31 by aandom            #+#    #+#             */
/*   Updated: 2023/04/19 15:10:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	*path;
	int		code;
	char	**c_paths;
	char	*cmd;
	int		tube[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipe;

int		is_comand_empty(char *str);
char	*get_path(char **env);
char	*extract_cmd(char *cpar, t_pipe *pdata);
void	first_child(t_pipe *pdata, char **av, char **env_p);
void	second_child(t_pipe *pdata, char **av, char **env_p);
void	close_clean_pipe(t_pipe **pipe);
int		fork_error(t_pipe *pdata);
void	cmd_not_found(char *cmd);
void	empty_cmd(t_pipe *pdata);
int		clean_cmd_n_found(t_pipe *pdata, char **cmdpar);
int		check_permission(t_pipe *pdata, int code);
int		execve_error(char *cmd, char **cmdpar, t_pipe *pdata);

#endif