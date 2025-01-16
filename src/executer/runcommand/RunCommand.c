/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunCommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:03 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:03 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	run_multiple_command(t_core *g_core, t_cmdlist *cmd_list)
{
	int			*fd;

	fd = create_pipe();
	while (cmd_list)
	{
		switch_pipe(&fd);
		pipe(&fd[2]);
		cmd_list->pid = fork();
		if (cmd_list->pid <= 0)
			run_process(g_core, cmd_list, fd, 2);
		cmd_list = cmd_list->next;
		if (fd[4] && fd[5])
		{
			close(fd[4]);
			close(fd[5]);
			fd[4] = 0;
			fd[5] = 0;
		}
	}
	clear_pipe(fd);
	wait_all(g_core);
}

void	run_single_command(t_core *g_core, t_cmdlist *cmd_list, int *fd)
{
	if (cmd_list->infile != SSTDERR && cmd_list->outfile != SSTDERR)
		exec_command(g_core, cmd_list, fd, -1);
}
