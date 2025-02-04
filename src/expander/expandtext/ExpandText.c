/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandText.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:34 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:34 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	expand_envs(t_core *g_core, char **dst, char *ptr)
{
	t_env	*copy_envs;

	copy_envs = g_core->env_table;
	while (copy_envs)
	{
		if (str_compare(ptr, copy_envs->env_name))
		{
			own_strjoin(dst, copy_envs->content);
			break ;
		}
		copy_envs = copy_envs->next;
	}
}

void	expand_order(t_core *g_core, char **dst, char **src)
{
	if (**src == *DOLLAR)
		expand_dollar(g_core, dst, src);
	else
	{
		if (**src == *TILDA && *(*src + 1) != *DOUBLE_QUOTE)
			expand_envs(g_core, dst, "HOME");
		else
			own_strjoin(dst, "~");
	}
}
