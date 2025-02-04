/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:10:24 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:10:24 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "macros.h"
# include "tables.h"

// MAIN
void	executer(t_core *g_core);

// RUNCOMMAND
void	run_single_command(t_core *g_core, t_cmdlist *cmd_list, int *fd);
void	run_multiple_command(t_core *g_core, t_cmdlist *cmd_list);

void	exec_command(t_core *g_core, t_cmdlist *cmd_node, int *fd,
			int fd_index);
char	*get_cmd(char *cmd);

void	run_process(t_core *g_core, t_cmdlist *cmd_list, int *fd,
			int fd_index);
void	wait_all(t_core *g_core);

int		*create_pipe(void);
void	clear_pipe(int *fd);
void	switch_pipe(int **fd);

// BUILTIN
void	run_builtin(t_core *g_core, t_cmdlist *cmd_node, int *fd,
			int fd_index);
int		is_builtin(char *cmd);

void	run_cd(t_core *g_core, t_cmdlist *cmd_node);
void	cd_single_arg(t_core *g_core);
void	cd_double_arg(t_core *g_core, t_cmdlist *cmd_node);
int		change_dir(t_core *g_core, char *path);
int		update_pwd_from_export(t_core *g_core,
			char *pwd_name, char *pwd_content);

void	run_echo(t_cmdlist *cmd_node);

void	run_unset(t_core *g_core, t_cmdlist *cmd_node);
void	delete_env(t_core *g_core, char *name);

void	run_env(t_core *g_core, t_cmdlist *cmd_node);

void	run_exit(t_core *g_core, t_cmdlist *cmd_node);
int		is_all_numeric(char *text);

void	run_export(t_core *g_core, t_cmdlist *cmd_node);
void	single_export_arg(t_core *g_core, t_cmdlist *cmd_node);
void	double_export_arg(t_core *g_core, char *env_cmd);
int		change_env(t_core *g_core, char *envname, char *arg, int is_equal);

void	run_pwd(t_cmdlist *cmd_node);

// EXECVE
void	run_execve(t_core *g_core, t_cmdlist *cmd_node, int *fd, int fd_index);

// DUPw
void	create_dup(t_core *g_core, t_cmdlist *cmd_list, int *fd, int fd_index);

#endif
