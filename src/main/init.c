/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:14 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:14 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_usrname(t_core *g_core)
{
	t_env	*temp_env;

	temp_env = g_core->env_table;
	while (temp_env)
	{
		if (str_compare("USER", temp_env->env_name))
			g_core->usrname = temp_env->content;
		temp_env = temp_env->next;
	}
}

void	init_core(t_core *g_core, char **env)
{
	g_core->pid = 1;
	fill_envs(g_core, env);
	set_metachars(g_core);
	get_usrname(g_core);
	g_core->exec_output = 0;
	g_core->old_exec_output = 0;
}
