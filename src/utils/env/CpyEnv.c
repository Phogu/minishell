/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpyEnv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:55 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:55 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	get_env_len(t_core *g_core)
{
	t_env	*env_list;
	int		count;

	env_list = g_core->env_table;
	count = 0;
	while (env_list)
	{
		if (env_list->content)
			count++;
		env_list = env_list->next;
	}
	return (count);
}

char	**get_env_cpy(t_core *g_core)
{
	int		env_len;
	char	**envlist;
	char	*temp_env;
	t_env	*temp_envlist;

	env_len = get_env_len(g_core);
	envlist = (char **)malloc(sizeof(char *) * (env_len + 1));
	envlist[env_len] = NULL;
	temp_envlist = g_core->env_table;
	while (temp_envlist)
	{
		if (temp_envlist->content)
		{
			temp_env = NULL;
			own_strjoin(&temp_env, temp_envlist->env_name);
			str_addchar(&temp_env, '=');
			own_strjoin(&temp_env, temp_envlist->content);
			envlist[--env_len] = temp_env;
		}
		temp_envlist = temp_envlist->next;
	}
	return (envlist);
}

void	free_env_cpy(char **envlist)
{
	char	**temp_envlist;

	temp_envlist = envlist;
	while (*temp_envlist)
		free(*(temp_envlist++));
	free(envlist);
}
