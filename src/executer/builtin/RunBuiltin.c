/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunBuiltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:13:23 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:13:23 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (str_compare(cmd, "echo"))
		return (ECHO);
	else if (str_compare(cmd, "cd"))
		return (CD);
	else if (str_compare(cmd, "pwd"))
		return (PWD);
	else if (str_compare(cmd, "export"))
		return (EXPORT);
	else if (str_compare(cmd, "unset"))
		return (UNSET);
	else if (str_compare(cmd, "env"))
		return (ENV);
	else if (str_compare(cmd, "exit"))
		return (EXIT);
	return (0);
}

void	run_builtin(t_core *g_core, t_cmdlist *cmd_node, int *fd, int fd_index)
{
	if (fd)
		create_dup(g_core, cmd_node, fd, fd_index);
	if (g_core->builtin == ECHO)
		run_echo(cmd_node);
	else if (g_core->builtin == CD)
		run_cd(g_core, cmd_node);
	else if (g_core->builtin == PWD)
		run_pwd(cmd_node);
	else if (g_core->builtin == EXPORT)
		run_export(g_core, cmd_node);
	else if (g_core->builtin == UNSET)
		run_unset(g_core, cmd_node);
	else if (g_core->builtin == ENV)
		run_env(g_core, cmd_node);
	else if (g_core->builtin == EXIT)
		run_exit(g_core, cmd_node);
}
