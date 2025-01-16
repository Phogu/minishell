/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExportEnvControl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:04 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:04 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*valid_env(t_core *g_core, char *env)
{
	int	flag;

	flag = 0;
	if ((*env >= 'a' && *env <= 'z') || (*env >= 'A' && *env <= 'Z'))
		flag = 1;
	while (*env != ' ' && *env && *env != '=')
	{
		if ((*env > '0' && *env < '9' && !flag)
			|| compare_metachars(g_core, env))
			return (NULL);
		env++;
	}
	return (env);
}

char	*env_name_control(t_core *g_core, char *env)
{
	char	*env_temp;

	if (!env || *env == ' ' || *env == '=')
		return (NULL);
	env_temp = env;
	env_temp = valid_env(g_core, env_temp);
	if (!env_temp || (*env_temp != '=' && *env_temp))
		return (NULL);
	if (*env_temp == '=')
		return (++env_temp);
	else
		return (env_temp);
}

int	env_arg_control(t_core *g_core, char *env)
{
	if (env_name_control(g_core, env))
		return (1);
	g_core->exec_output = 1;
	return (0);
}
