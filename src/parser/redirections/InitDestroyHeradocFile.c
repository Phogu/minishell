/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitDestroyHeradocFile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:36 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:36 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	close_heredoc_file(t_core *g_core)
{
	if (g_core->heredoc_fd > SSTDERR)
	{
		g_core->heredoc_fd = close(g_core->heredoc_fd);
		g_core->heredoc_fd = 0;
	}
}

void	open_heredoc_file(t_core *g_core, char *create_mode)
{
	char	*heracoc_path;
	char	ptr[256];

	heracoc_path = NULL;
	own_strjoin(&heracoc_path, (char *)getcwd(ptr, 256));
	str_addchar(&heracoc_path, '/');
	own_strjoin(&heracoc_path, "heredoc");
	if (str_compare(create_mode, "READ"))
		g_core->heredoc_fd = open(heracoc_path, O_RDONLY, 0777);
	else
		g_core->heredoc_fd = open(heracoc_path,
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	free(heracoc_path);
}
