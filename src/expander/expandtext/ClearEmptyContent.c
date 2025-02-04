/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClearEmptyContent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:19 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:19 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	clear_void_contents(t_core *g_core)
{
	t_lexlist	*lex_list;
	t_lexlist	*temp_lex_list;

	lex_list = g_core->lex_table;
	temp_lex_list = g_core->lex_table;
	while (lex_list)
	{
		if (!lex_list->content)
		{
			if (lex_list == g_core->lex_table)
			{
				g_core->lex_table = g_core->lex_table->next;
				temp_lex_list = temp_lex_list->next;
			}
			else
				temp_lex_list->next = lex_list->next;
			free(lex_list);
			lex_list = temp_lex_list;
		}
		temp_lex_list = lex_list;
		if (lex_list)
			lex_list = lex_list->next;
	}
}

// şimdilik şurası kapalı olsun global değişken değiştiriyorum. 

void	brace_check(t_core *g_core, char **dst, char **src)
{
	char	*ptr;
	int		count;

	ptr = *src + 1;
	count = 0;
	while (*ptr != '}' && *ptr)
	{
		count++;
		ptr++;
	}
	ptr = ft_strpcpy(NULL, (*src) + 2, count - 1);
	expand_envs(g_core, dst, ptr);
	free(ptr);
	*src += count + 2;
	return ;
}
