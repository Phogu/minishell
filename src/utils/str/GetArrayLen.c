/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetArrayLen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:20:16 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:20:16 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	get_array_len(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}
