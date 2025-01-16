/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeParser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:59 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:59 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_parser(t_core *g_core)
{
	t_cmdlist	*parser;
	t_cmdlist	*temp_parser;

	parser = g_core->cmd_table;
	while (parser)
	{
		temp_parser = parser;
		parser = parser->next;
		free_filelist(temp_parser->files);
		if (temp_parser->path)
			free(temp_parser->path);
		if (temp_parser->heredoc_values)
			free(temp_parser->heredoc_values);
		free(temp_parser);
	}
	g_core->cmd_table = NULL;
}

void	free_filelist(t_filelist *files)
{
	t_filelist	*temp_files;

	while (files)
	{
		temp_files = files;
		files = files->next;
		if (temp_files->fd > SSTDERR)
			close(temp_files->fd);
		free(temp_files);
	}
}
