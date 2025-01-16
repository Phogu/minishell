/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UpdateLoop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:27 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:27 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_loop(t_core	*g_core)
{
	g_core->old_exec_output = g_core->exec_output;
	g_core->exec_output = 0;
	g_core->is_read_arg = 0;
}

void	update_history(char *cmd)
{
	char	*ptr;

	if (!cmd)
		return ;
	ptr = cmd;
	trim_spaces(&ptr);
	if (!*ptr)
		return ;
	add_history(cmd);
}
