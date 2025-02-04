/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunProcess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:07 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:07 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	run_process(t_core *g_core, t_cmdlist *cmd_list, int *fd, int fd_index)
{
	if (cmd_list->infile != SSTDERR && cmd_list->outfile != SSTDERR)
		exec_command(g_core, cmd_list, fd, fd_index);
	else
		clear_pipe(fd);
	free_for_loop(g_core);
	free_core(g_core);
	exit(g_core->exec_output);
}

void	wait_all(t_core *g_core)
{
	t_cmdlist	*cmd_list;

	cmd_list = g_core->cmd_table;
	while (cmd_list)
	{
		if (!cmd_list->next)
			waitpid(cmd_list->pid, &g_core->exec_output, 0);
		else
			waitpid(cmd_list->pid, 0, 0);
		cmd_list = cmd_list->next;
	}
	g_core->exec_output = WEXITSTATUS(g_core->exec_output);
}
