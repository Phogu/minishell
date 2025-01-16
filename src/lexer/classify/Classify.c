/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:50 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:50 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
	olusturulmus lexer bagli listesinde ki her nodeda bulunan 
	sozcuklerin tipi belirlenir.
	bu olusturulan tiplerin karsiliklari "lexer.h"'da define edilmistir
	oradan karsiliklari gorulebilir ve kontrol islemleri
	orda define edilmis degiskenler uzerinden yapilabilir.
*/

void	classify(t_core *g_core, t_lexlist *lex_table)
{
	char	*metachars;

	if (!lex_table)
		return ;
	while (lex_table)
	{
		metachars = compare_metachars(g_core, lex_table->content);
		if (metachars)
			lex_table->type = (*metachars - 1) * ft_strlen(metachars);
		else
			lex_table->type = 0;
		lex_table = lex_table->next;
	}
}
