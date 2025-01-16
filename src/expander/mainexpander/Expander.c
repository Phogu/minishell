/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:15:40 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:15:40 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	expander(t_core *g_core)
{
	if (g_core->exec_output == 2)
		return ;
	expand_values_from_lexlist(g_core);
	clear_void_contents(g_core);
}
