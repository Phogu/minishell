/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetEnvName.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:07 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:07 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_env_name(char *content)
{
	int		env_name_len;
	char	*name;
	char	*temp_name;

	env_name_len = get_env_name_count(content);
	if (!env_name_len)
		return (NULL);
	name = (char *)malloc(sizeof(char) * (env_name_len + 1));
	temp_name = name;
	while (content && *content && *content != '=')
		*(temp_name++) = *(content++);
	*temp_name = 0;
	return (name);
}

int	get_env_name_count(char *env_arg)
{
	int	count;

	count = 0;
	while (env_arg && *env_arg && *(env_arg++) != '=')
		count++;
	return (count);
}
