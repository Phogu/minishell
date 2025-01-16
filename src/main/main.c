/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:17:18 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:17:19 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_core_sgn	*g_sgn_core;

int	main(int argc, char **argv, char **env)
{
	t_core	*g_core;

	g_core = malloc(sizeof(t_core));
	(void)argc;
	(void)argv;
	g_sgn_core = (t_core_sgn *)g_core;
	init_core(g_core, env);
	signal(SIGINT, &sig_handler);
	while (1)
	{
		update_loop(g_core);
		g_core->cmd = readline("minishell : ");
		exit_signal_check(g_core);
		lexer(g_core);
		expander(g_core);
		parser(g_core);
		executer(g_core);
		update_history(g_core->cmd);
		free_for_loop(g_core);
	}
	free_core(g_core);
}
