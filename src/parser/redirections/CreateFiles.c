/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateFiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:17 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:17 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	create_files(t_core *g_core, t_cmdlist *node)
{
	t_filelist	*temp_file;

	if (!node)
		return ;
	run_heredocs(g_core, node);
	if (g_core->exec_output || !node)
		return ;
	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (*temp_file->metachar == *SINGLE_GREAT)
				create_outfile(node, temp_file);
			else
				create_infile(g_core, node, temp_file);
			if (temp_file->fd == SSTDERR)
			{
				g_core->exec_output = 1;
				break ;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}
