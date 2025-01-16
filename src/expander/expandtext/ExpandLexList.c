/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandLexList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:30 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:30 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
Bu fonksiyon lextable daki düğümleri tek tek inceliyor. 
her düğümün contentini değiştiriyor. artık düğümler içerisinde
yazdırılmaya ve işlenmeye hazır kelime grupları var.
*/
void	expand_values_from_lexlist(t_core *g_core)
{
	t_lexlist	*lex_table;

	lex_table = g_core->lex_table;
	while (lex_table)
	{
		if (lex_table->type == TEXT)
			expand_text(g_core, lex_table, 0);
		else if (lex_table->next && lex_table->type != SIGN_PIPE)
		{
			if (lex_table->type != SIGN_DOUBLE_LESS)
				expand_text(g_core, lex_table->next, 1);
			lex_table = lex_table->next;
		}
		lex_table = lex_table->next;
	}
}

/*
CHAT GPT:

Bu fonksiyon, tek tırnak, çift tırnak, dolar işareti
ve tilde karakterlerini özel olarak işler ve bu karakterlerin 
içeriğini dönüştürür. Meta karakterler (örneğin, > veya <) sonrası
ise sonuçta bir şey üretmemesi gerektiği durumları kontrol eder.
*/

void	expand_text(t_core *g_core, t_lexlist *lex_table, int is_after_meta)
{
	char	*cmd;
	int		flag;
	char	*ptr;

	cmd = lex_table->content;
	ptr = NULL;
	flag = 0;
	while (*cmd)
	{
		if (*cmd == '\'' && (!flag || flag == 1))
			flag = flag ^ 1;
		else if (*cmd == '\"' && (!flag || flag == 2))
			flag = flag ^ 2;
		else if ((!flag || flag == 2) && (*cmd == *DOLLAR || *cmd == *TILDA))
			expand_order(g_core, &ptr, &cmd);
		else
			str_addchar(&ptr, *cmd);
		cmd++;
	}
	if (is_after_meta && !ptr)
		return ;
	free(lex_table->content);
	lex_table->content = ptr;
}
