/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:14:13 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:14:13 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	executer(t_core *g_core)
{
	if (!g_core->cmd_table)
		return ;
	else if (!g_core->cmd_table->next)
		run_single_command(g_core, g_core->cmd_table, NULL);
	else
		run_multiple_command(g_core, g_core->cmd_table);
}
