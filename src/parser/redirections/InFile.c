/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InFile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:32 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:32 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	create_infile(t_core *g_core, t_cmdlist *node, t_filelist *file)
{
	char	*pwd;
	char	ptr[256];

	if (file->metachar[1] == DOUBLE_LESS[1])
	{
		node->infile = HEREDOC;
		return ;
	}
	if (raise_file_error(file, &node->infile))
		return ;
	pwd = NULL;
	own_strjoin(&pwd, (char *)getcwd(ptr, 256));
	str_addchar(&pwd, '/');
	own_strjoin(&pwd, file->filename);
	if (!access(pwd, F_OK))
		file->fd = open(pwd, O_RDONLY, 0777);
	if (file->fd <= SSTDERR && file->fd != HEREDOC)
	{
		print_error("-bash: ", file->filename,
			": No such file or directory\n");
		g_core->exec_output = 1;
		file->fd = SSTDERR;
	}
	node->infile = file->fd;
	free(pwd);
}
