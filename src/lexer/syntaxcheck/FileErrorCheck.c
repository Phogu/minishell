/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileErrorCheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:34 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:34 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	file_error_check(t_core *g_core, t_lexlist *lex_list)
{
	if (!lex_list->next || (lex_list->next && lex_list->next->type != TEXT))
	{
		if (lex_list->next)
		{
			print_error("-bash: syntax error near unexpected token '",
				lex_list->next->content, "'\n");
			g_core->exec_output = 2;
			free_lexer_without_heredoc(g_core, lex_list);
			return (0);
		}
		else
		{
			print_error("-bash: syntax error near unexpected token '",
				"newline", "'\n");
			g_core->exec_output = 2;
			free_lexer_without_heredoc(g_core, lex_list);
			return (0);
		}
	}
	return (1);
}
