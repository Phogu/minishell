/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeLexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:17 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:17 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	skip_heredoc(t_lexlist **lex, t_lexlist **temp, t_lexlist *stop, int *flag)
{
	if (stop == *lex)
		*flag |= 1;
	if ((*lex)->type == SIGN_DOUBLE_LESS && !*flag)
	{
		if ((*lex) && (*lex) != stop)
			*lex = (*lex)->next;
		*temp = *lex;
		*lex = (*lex)->next;
		return (1);
	}
	return (0);
}

void	free_lexer_without_heredoc(t_core *g_core, t_lexlist *stop_list)
{
	t_lexlist	*lexer;
	t_lexlist	*temp_lexer;
	int			flag;

	lexer = g_core->lex_table;
	flag = 0;
	while (lexer)
	{
		if (skip_heredoc(&lexer, &temp_lexer, stop_list, &flag))
			continue ;
		if (g_core->lex_table == lexer)
		{
			g_core->lex_table = g_core->lex_table->next;
			temp_lexer = g_core->lex_table;
		}
		else
			temp_lexer->next = lexer->next;
		free(lexer->content);
		free(lexer);
		if (g_core->lex_table == temp_lexer)
			lexer = temp_lexer;
		else
			lexer = temp_lexer->next;
	}
}

void	free_lexer(t_core *g_core)
{
	t_lexlist	*lexer;
	t_lexlist	*temp_lexer;

	lexer = g_core->lex_table;
	while (lexer)
	{
		temp_lexer = lexer;
		lexer = lexer->next;
		if (temp_lexer->content)
			free(temp_lexer->content);
		free(temp_lexer);
	}
	g_core->lex_table = NULL;
}
