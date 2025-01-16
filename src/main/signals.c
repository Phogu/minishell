/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:23 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:23 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sig_handler(int signum)
{
	if (g_sgn_core->is_read_arg != 1)
		ft_printf("\n%s", ft_strtonl(" "));
	(void)signum;
	if (signal_in_reading(g_sgn_core))
		return ;
	if (signal_while_cmd_works(g_sgn_core))
		return ;
	g_sgn_core->exec_output = SIGNAL_C;
	write(1, "\n", 1);
	free_for_loop((t_core *)g_sgn_core);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	signal_in_reading(t_core_sgn *g_core)
{
	if (g_core->is_read_arg && g_core->pid == 0)
	{
		free_for_loop2(g_core);
		free_core((t_core *)g_core);
		exit(SIGNAL_C);
	}
	else if (g_core->is_read_arg && g_core->pid != 0)
	{
		g_core->exec_output = SIGNAL_C;
		return (1);
	}
	return (0);
}

int	signal_while_cmd_works(t_core_sgn *g_core)
{
	t_cmdlist	*cmd_list;
	int			return_value;

	return_value = 0;
	cmd_list = g_core->cmd_table;
	while (cmd_list)
	{
		if (cmd_list->pid >= 0)
			return_value |= waitpid(cmd_list->pid, 0, 0);
		cmd_list = cmd_list->next;
	}
	if (return_value)
	{
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	exit_signal_check(t_core *g_core)
{
	if (!g_core->cmd)
	{
		ft_printf("\n");
		print_error("^+D : Exits ./minishell\n", 0, 0);
		free_core(g_core);
		exit(EXIT_SUCCESS);
	}
}
