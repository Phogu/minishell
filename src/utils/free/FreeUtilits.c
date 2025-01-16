/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeUtilits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:29 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:29 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_metachars(t_core *g_core)
{
	char	**temp_metachars;

	temp_metachars = g_core->metachars;
	if (!temp_metachars)
		return ;
	while (temp_metachars && *temp_metachars)
		free(*(temp_metachars++));
	free(g_core->metachars);
}

void	free_envtable(t_core *g_core)
{
	t_env	*env;
	t_env	*temp_env;

	env = g_core->env_table;
	while (env)
	{
		temp_env = env;
		env = env->next;
		free(temp_env->env_name);
		free(temp_env->content);
		free(temp_env);
	}
}

void	free_title(t_core *g_core)
{
	free(g_core->title.full_title);
	free(g_core->title.head);
}
