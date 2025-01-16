/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:11:05 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:11:05 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLES_H
# define TABLES_H

typedef struct s_title
{
	char	*head;
	char	*full_title;
}	t_title;

typedef struct s_env
{
	char			*env_name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_lexlist
{
	char				type;
	char				*content;
	struct s_lexlist	*next;
}	t_lexlist;

typedef struct s_filelist
{
	char				*metachar;
	char				*filename;
	int					fd;
	struct s_filelist	*next;
}	t_filelist;

typedef struct s_cmdlist
{
	int					infile;
	int					outfile;
	int					pid;
	char				*heredoc_values;
	char				*cmd;
	char				**path;
	t_filelist			*files;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_need
{
	int		i;
	int		j;
	int		s;
	int		flag;
}	t_need;

typedef struct s_core
{
	int			pid;
	int			exec_output;
	int			old_exec_output;
	int			heredoc_fd;
	int			is_read_arg;
	int			builtin;
	char		*replace;
	char		*usrname;
	char		*cmd;
	char		**metachars;
	char		*string;
	t_env		*env_table;
	t_lexlist	*lex_table;
	t_cmdlist	*cmd_table;
	t_title		title;
	t_need		n;
}	t_core;

typedef struct s_core_sgn
{
	int			pid;
	int			exec_output;
	int			old_exec_output;
	int			heredoc_fd;
	int			is_read_arg;
	int			builtin;
	char		*replace;
	char		*usrname;
	char		*cmd;
	char		**metachars;
	char		*string;
	t_env		*env_table;
	t_lexlist	*lex_table;
	t_cmdlist	*cmd_table;
	t_title		title;
	t_need		n;
}	t_core_sgn;

#endif
