/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunExit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:13:42 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:13:42 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_all_numeric(char *text)
{
	while (text && *text)
	{
		if (!(*text >= '0' && *text <= '9'))
			return (0);
		text++;
	}
	return (1);
}

void	len1_handle(t_core *g_core, t_cmdlist *cmd_node)
{
	if (is_all_numeric(cmd_node->path[1]))
		g_core->exec_output = ft_atoi(cmd_node->path[1]);
	else
	{
		print_error("bash: exit: ",
			cmd_node->path[1], ": numeric argument required\n");
		g_core->exec_output = 255;
		return ;
	}
}

void	run_exit(t_core *g_core, t_cmdlist *cmd_node)
{
	int	array_len;

	array_len = get_array_len(&cmd_node->path[1]);
	if (array_len > 1)
	{
		print_error("bash: exit: too many arguments\n", NULL, NULL);
		g_core->exec_output = 1;
		return ;
	}
	else if (array_len == 1)
	{
		if (is_all_numeric(cmd_node->path[1]))
			g_core->exec_output = ft_atoi(cmd_node->path[1]);
		else
		{
			return (len1_handle(g_core, cmd_node));
		}
	}
	else
		g_core->exec_output = 0;
	free_for_loop(g_core);
	free_core(g_core);
	exit(g_core->exec_output % 256);
}
