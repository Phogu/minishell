/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heradoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:24 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:24 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	run_heredocs(t_core *g_core, t_cmdlist *node)
{
	t_filelist	*temp_file;

	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (temp_file->metachar[1] == DOUBLE_LESS[1])
			{
				if (!read_heredoc(g_core, node, temp_file->filename))
					return ;
				temp_file->fd = HEREDOC;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}

int	read_heredoc(t_core *g_core, t_cmdlist *node, char *eof)
{
	int		pid;
	int		fd[2];
	int		return_value;

	pipe(fd);
	pid = fork();
	g_core->is_read_arg = 1;
	g_core->pid = pid;
	if (!pid)
		fill_heredoc(g_core, eof, fd);
	close(fd[1]);
	waitpid(pid, &return_value, 0);
	return_value = WEXITSTATUS(return_value);
	if (return_value == SIGNAL_C)
	{
		close(fd[0]);
		update_history(g_core->cmd);
		free_for_loop(g_core);
		return (0);
	}
	g_core->is_read_arg = 0;
	set_heredoc_value(g_core, node, fd);
	return (1);
}

void	set_heredoc_value(t_core *g_core, t_cmdlist *node, int *fd)
{
	char	ptr[1];

	if (node->heredoc_values)
	{
		free(node->heredoc_values);
		node->heredoc_values = NULL;
	}
	while (read(fd[0], ptr, 1))
		str_addchar(&node->heredoc_values, *ptr);
	close(fd[0]);
	str_addchar(&g_core->cmd, '\n');
	own_strjoin(&g_core->cmd, node->heredoc_values);
}

void	fill_heredoc(t_core *g_core, char *eof, int *fd)
{
	char	*heredoc_lines;

	close(fd[0]);
	heredoc_lines = get_heredoc_values(eof);
	write(fd[1], heredoc_lines, ft_strlen(heredoc_lines));
	close(fd[1]);
	free(heredoc_lines);
	free_for_loop(g_core);
	free_core(g_core);
	exit(EXIT_SUCCESS);
}

char	*get_heredoc_values(char *eof)
{
	char	*line;
	char	*newline;
	int		is_begin;

	line = NULL;
	is_begin = 0;
	while (1)
	{
		newline = readline("> ");
		if (str_compare(eof, newline))
		{
			free(newline);
			break ;
		}
		else if (is_begin++)
			str_addchar(&line, '\n');
		own_strjoin(&line, newline);
		if (newline)
			free(newline);
	}
	str_addchar(&line, '\n');
	return (line);
}
