/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:59:22 by aandom            #+#    #+#             */
/*   Updated: 2023/04/20 10:02:17 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "get_next_line/get_next_line.h"

typedef struct s_pipe
{
	char	*path;
	char	**c_paths;
	int		code;
	char	*cmd;
	int		cmd_index;
	int		*p_arr;
	int		pipe_num;
	int		fd_in;
	int		fd_out;
	int		here_doc;
	int		cmd_num;
	int		p_index;
}			t_pipe;

int		is_comand_empty(char *str);
int		is_here_doc(char *str);
void	set_here_doc(char **str, t_pipe *pdata);
void	here_doc(char **av);
void	close_clean_pipe(t_pipe **pipe);
int		fork_error(t_pipe *pdata);
void	empty_cmd(t_pipe *pdata);
int		clean_cmd_n_found(t_pipe *pdata, char *cmd, char **cmdpar);
void	cmd_not_found(char *cmd);
int		check_permission(t_pipe *pdata, int code);
void	close_pipes(t_pipe *pipex);
void	check_dir(t_pipe *pdata, char **cmd, char **cmdpar);
void	is_dir(char *str, t_pipe *pdata);
char	*get_path(char **env);
char	*extract_cmd(char *cpar, t_pipe *pdata);
int		no_file_or_directory(int ac, char **av);
int		ft_exit(t_pipe *pdata, int code, char *file);
int		valid_n_argument(int ac, char **av);
void	child(t_pipe *pdata, char **av, char **env_p);
int		execve_error(char *cmd, char **cmdpar, t_pipe *pdata);

#endif