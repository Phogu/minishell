/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:01 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:01 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_core(t_core *g_core)
{
	free_metachars(g_core);
	free_envtable(g_core);
	rl_clear_history();
}

void	free_for_loop(t_core *g_core)
{
	if (g_core->cmd)
	{
		free(g_core->cmd);
		g_core->cmd = NULL;
	}
	if (g_core->lex_table)
		free_lexer(g_core);
	if (g_core->cmd_table)
		free_parser(g_core);
	close_heredoc_file(g_core);
}

void	free_for_loop2(t_core_sgn *g_core)
{
	if (g_core->cmd)
	{
		free(g_core->cmd);
		g_core->cmd = NULL;
	}
	if (g_core->lex_table)
		free_lexer((t_core *)g_core);
	if (g_core->cmd_table)
		free_parser((t_core *)g_core);
	close_heredoc_file((t_core *)g_core);
}
