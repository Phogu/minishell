/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetMissingArg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:41 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:41 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_missing_arg(t_core *g_core)
{
	char	*ptr;
	int		fd[2];
	char	c[1];

	pipe(fd);
	if (!read_missing_arg(g_core, fd))
		return (NULL);
	ptr = NULL;
	while (read(fd[0], c, 1))
		str_addchar(&ptr, *c);
	close(fd[0]);
	return (ptr);
}

int	read_missing_arg(t_core *g_core, int *fd)
{
	int		pid;
	int		return_value;

	pid = 1;
	pid = fork();
	g_core->pid = pid;
	g_core->is_read_arg = 1;
	if (!pid)
		read_missing_arg_value(g_core, fd);
	close(fd[1]);
	waitpid(pid, &return_value, 0);
	g_core->is_read_arg = 0;
	return_value = WEXITSTATUS(return_value);
	if (return_value == SIGNAL_C)
	{
		close(fd[0]);
		update_history(g_core->cmd);
		free_for_loop(g_core);
		return (0);
	}
	return (1);
}

void	read_missing_arg_value(t_core *g_core, int *fd)
{
	char	*ptr;

	close(fd[0]);
	while (1)
	{
		ptr = readline("> ");
		if (!control_valid_arg(ptr))
			continue ;
		write(fd[1], ptr, ft_strlen(ptr));
		close(fd[1]);
		free(ptr);
		free_for_loop(g_core);
		free_core(g_core);
		exit(EXIT_SUCCESS);
	}
}

int	control_valid_arg(char *ptr)
{
	char	*str;

	if (!ptr)
		return (0);
	str = ptr;
	trim_spaces(&str);
	if (!*str)
	{
		free(ptr);
		return (0);
	}
	return (1);
}
