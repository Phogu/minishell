/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PipeErrorCheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:49 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:49 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	pipe_error_check(t_core *g_core, t_lexlist *lex_list)
{
	if (lex_list->next && lex_list->next->type == SIGN_PIPE)
		return (print_lex_error(g_core, lex_list));
	else if (!lex_list->next)
		return (run_miss_arg(g_core, lex_list));
	return (1);
}

int	run_miss_arg(t_core *g_core, t_lexlist *lex_list)
{
	char	*ptr;

	ptr = get_missing_arg(g_core);
	if (!ptr)
		return (1);
	create_lexlist(g_core, ptr, &lex_list);
	classify(g_core, lex_list);
	str_addchar(&g_core->cmd, ' ');
	own_strjoin(&g_core->cmd, ptr);
	free(ptr);
	if (str_compare(lex_list->next->content, PIPE))
		return (-1);
	return (1);
}
