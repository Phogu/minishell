/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintError.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:18 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:18 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	print_lex_error(t_core *g_core, t_lexlist *lex_list)
{
	print_error("-bash: syntax error near unexpected token '",
		lex_list->content, "'\n");
	g_core->exec_output = 2;
	free_lexer_without_heredoc(g_core, lex_list);
	return (0);
}

void	print_error(char *ptr1, char *ptr2, char *ptr3)
{
	write(2, "\033[0;31m", 7);
	if (ptr1)
		write(2, ptr1, ft_strlen(ptr1));
	if (ptr2)
		write(2, ptr2, ft_strlen(ptr2));
	if (ptr3)
		write(2, ptr3, ft_strlen(ptr3));
	write(2, "\033[0;32m", 7);
}
