/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunEcho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:13:34 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:13:34 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	run_echo(t_cmdlist *cmd_node)
{
	char	**path;
	int		is_n;
	int		i;

	is_n = 0;
	i = 0;
	path = &cmd_node->path[1];
	if (path[i] && str_compare(path[i], "-n"))
	{
		is_n = 1;
		i++;
	}
	while (path[i])
	{
		if (path[i] && str_compare(path[i], "-n") != 1)
			write(cmd_node->outfile, path[i], ft_strlen(path[i]));
		if (path[i++] && path[i] && str_compare(path[i - 1], "-n") != 1)
			write(cmd_node->outfile, " ", 1);
	}
	if (is_n && i >= 2)
		write(cmd_node->outfile, "\033[0;32m%\033[0m", 10);
	write(cmd_node->outfile, "\n", 1);
}
