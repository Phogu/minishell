/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TrimSpace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:20:33 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:20:33 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	Gelen komutu bosluk gordukce adres uzerinde arttirir
	boylece geldigi fonksiyonda da artmis olur.
*/

size_t	trim_spaces(char **cmd_line)
{
	size_t	count;

	count = 0;
	if (!*cmd_line)
		return (count);
	while (**cmd_line == 32)
	{
		count++;
		(*cmd_line)++;
	}
	return (count);
}
