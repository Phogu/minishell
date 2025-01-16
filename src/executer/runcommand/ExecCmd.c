/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecCmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:14:50 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:14:50 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exec_command(t_core *g_core, t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	*cmd;

	if (cmd_node && !cmd_node->cmd)
		return ;
	cmd = get_cmd(cmd_node->cmd);
	g_core->builtin = is_builtin(cmd);
	if (g_core->builtin)
		run_builtin(g_core, cmd_node, fd, fd_index);
	else
		run_execve(g_core, cmd_node, fd, fd_index);
}

char	*get_cmd(char *cmd)
{
	int		command_len;

	command_len = 0;
	while (*cmd)
	{
		command_len++;
		if (*cmd == '/')
			command_len = 0;
		cmd++;
	}
	return (cmd - command_len);
}
