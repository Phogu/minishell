/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:16:22 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:16:23 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	Lexer 4 asamali prjenin ilk asamasidir. Burada amac
	girilen karisik komutlari sozcuk yapilarina ayirmaktir.
	orn komut: <a.txt cat| ls| wc -l | echo "ahmet $HOME''"selam    
	lexer calistiktan sonra bagil liste deki
	contentlerin ciktisi soyle olmalidir:
	<, a.txt, cat, |, ls, |, wc, -l, |, echo, "ahmet $HOME''"selam'$PATH'
*/
void	lexer(t_core *g_core)
{
	g_core->lex_table = NULL;
	create_lexlist(g_core, g_core->cmd, &(g_core->lex_table));
	classify(g_core, g_core->lex_table);
	syntax_check(g_core);
}
