/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heredoc_env_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:28 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:29 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
normdan kaçmak için(void)new yazıldı.
*/
void	set_n(t_core *g_core, char *new)
{
	(void)new;
	g_core->n.i = 0;
	g_core->n.j = 0;
	g_core->n.s = 0;
}

char	*replace_line(t_core *g_core, char *old, int begin, int start)
{
	char	*new;

	new = malloc(sizeof(char) * 100000);
	set_n(g_core, new);
	while (old[g_core->n.i])
	{
		if (g_core->n.i == begin)
		{
			while ((size_t)g_core->n.s < ft_strlen(g_core->replace))
			{
				new[g_core->n.j] = g_core->replace[g_core->n.s];
				g_core->n.j++;
				g_core->n.s++;
			}
			g_core->n.i = g_core->n.i + start - 1;
		}
		else
		{
			new[g_core->n.j] = old[g_core->n.i];
			g_core->n.j++;
		}
		g_core->n.i++;
	}
	new[g_core->n.j] = '\0';
	return (new);
}

char	*env_loop(t_core *g_core, char *name, char *line)
{
	char	*temp;

	while (line[g_core->n.i])
	{
		if (line[g_core->n.i] == '$' && line[g_core->n.i + 1] != '\0' \
		&& line[g_core->n.i + 1] != ' ')
		{
			while (g_core->n.flag == 0 && (size_t)g_core->n.s < ft_strlen(line))
			{
				temp = ft_strpcpy(NULL, &line[g_core->n.i + 1], g_core->n.s);
				if (get_env(g_core, temp) != NULL)
				{
					g_core->n.flag = 1;
					name = get_env(g_core, temp);
					g_core->n.j = g_core->n.i;
				}
				g_core->n.s++;
			}
		}
		g_core->n.i++;
	}
	return (name);
}

char	*env_check(t_core *g_core, char *line)
{
	char	*newline;

	g_core->n.flag = 0;
	g_core->replace = malloc(sizeof(char) * 100);
	set_n(g_core, g_core->replace);
	newline = malloc(sizeof(char) * 100000);
	g_core->replace = env_loop(g_core, g_core->replace, line);
	if (g_core->n.flag == 1)
		newline = replace_line(g_core, line, g_core->n.j, g_core->n.s);
	else
		newline = line;
	return (newline);
}
