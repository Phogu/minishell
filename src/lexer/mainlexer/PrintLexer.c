/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintLexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:26 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:26 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_lexer(t_core *g_core)
{
	t_lexlist	*lexer_temp;

	lexer_temp = g_core->lex_table;
	ft_printf ("~LEXER TABLE~\n");
	while (lexer_temp)
	{
		ft_printf("{type: %d, content: %s}\n", lexer_temp->type,
			lexer_temp->content);
		lexer_temp = lexer_temp->next;
	}
	ft_printf("\n\n");
}
