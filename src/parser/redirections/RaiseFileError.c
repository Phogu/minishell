/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RaiseFileError.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:45 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:18:45 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_directory_error(char *file_name)
{
	char	*temp_file_name;

	temp_file_name = file_name;
	while (file_name && *file_name)
	{
		if (*(file_name++) == '/')
		{
			print_error("-bash: ", temp_file_name, ": Is a directory\n");
			return (0);
		}
	}
	return (1);
}

int	raise_file_error(t_filelist *file, int *file_output)
{
	int		error;

	error = 0;
	if (!check_directory_error(file->filename))
		error = 1;
	if (!error && *file->filename == '\"')
	{
		error = 1;
		print_error("-bash: : No such file or directory\n", NULL, NULL);
	}
	else if (!error && *file->filename == '$')
	{
		error = 1;
		print_error("-bash: ", file->filename, ": ambiguous redirect\n");
	}
	if (!error)
		return (error);
	file->fd = SSTDERR;
	*file_output = file->fd;
	return (error);
}
