/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandCmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:14 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:14 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* CHAT GPT:
expand_cmd fonksiyonu "PATH" çevresel değişkenini arar ve bulur. 
Diyelim ki "PATH" değişkeninin değeri şu şekildedir: 
"/usr/bin:/bin:/usr/sbin"   */

void	expand_cmd(t_core *g_core, char **dst)
{
	t_env	*temp_env;

	temp_env = g_core->env_table;
	while (temp_env && *dst && **dst)
	{
		if (str_compare("PATH", temp_env->env_name))
		{
			expand_from_env_value(dst, temp_env->content);
			return ;
		}
		temp_env = temp_env->next;
	}
}

/* ":" karakterine göre bölümlere ayırır.
Yani, "/usr/bin", "/bin" ve "/usr/sbin"
Her bir parça, get_arg_from_env_value fonksiyonu tarafından kontrol edilir.
Örneğin, ilk parça olan "/usr/bin" kontrol edilir.
"ls -l" komutu bu parçayı bulmaya çalışır.
Eğer "/usr/bin/ls" varsa, bu yol geçerli
kabul edilir ve control_ptr işaretçisi ile yerine konur.*/

void	expand_from_env_value(char **dst, char *content)
{
	char	*control_ptr;

	while (content && *content)
	{
		control_ptr = get_arg_from_env_value(&content, *dst);
		if (!access(control_ptr, F_OK))
		{
			free(*dst);
			*dst = control_ptr;
			return ;
		}
		free(control_ptr);
	}
}

char	*get_arg_from_env_value(char **envs, char *search_arg_name)
{
	char	*ptr;
	int		count;
	char	*temp_envs;

	count = 0;
	temp_envs = *envs;
	while (*temp_envs && *temp_envs != ':')
	{
		count++;
		temp_envs++;
		(*envs)++;
	}
	if (!count)
		return (NULL);
	if (**envs)
		(*envs)++;
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	ptr[count] = 0;
	while (--count > -1)
		ptr[count] = *(--temp_envs);
	str_addchar(&ptr, '/');
	own_strjoin(&ptr, search_arg_name);
	return (ptr);
}
