/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SynaxCheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:54 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:54 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	syntax_check(t_core *g_core)
{
	t_lexlist	*lex_list;
	int			syntax_error;

	lex_list = g_core->lex_table;
	while (lex_list)
	{
		syntax_error = syntax_error_check(g_core, lex_list);
		if (syntax_error == -1)
			break ;
		else if (!syntax_error)
			continue ;
		if (g_core->lex_table)
			lex_list = lex_list->next;
		else
			lex_list = NULL;
	}
}

int	syntax_error_check(t_core *g_core, t_lexlist *lex_list)
{
	int	pipe_error;

	if (lex_list == g_core->lex_table && lex_list->type == SIGN_PIPE)
	{
		print_lex_error(g_core, lex_list);
		return (-1);
	}
	else if (lex_list->type != TEXT && lex_list->type != SIGN_PIPE)
	{
		if (!file_error_check(g_core, lex_list))
			return (-1);
	}
	else if (lex_list->type == SIGN_PIPE)
	{
		pipe_error = pipe_error_check(g_core, lex_list);
		if (pipe_error < 0)
			return (0);
		else if (!pipe_error)
			return (-1);
	}
	return (1);
}
