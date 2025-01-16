/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:07 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:07 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*    fill_cmdtable da procceess nodelarımızın içleri dolduruldu. 
dosya işlemleride filelist oluşturuldu.
cmd değişkeni belirlendi
node'path ler belirlendi (ls -la)
infile outfile standart olarak belirlendi
*/

void	parser(t_core *g_core)
{
	g_core->cmd_table = NULL;
	create_cmdtable(g_core, g_core->lex_table);
	fill_cmdtable(g_core);
	create_files(g_core, g_core->cmd_table);
}
