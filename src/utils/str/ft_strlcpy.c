/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:58 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:58 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*ft_strpcpy(char *dst, char *src, int count)
{
	char	*ptr;
	char	*return_ptr;
	int		index;

	if (!src || !count)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(dst) + count + 1));
	return_ptr = ptr;
	index = -1;
	while (dst && *dst)
		*(ptr++) = *(dst++);
	while (++index < count && src && *src)
		*(ptr++) = *(src++);
	*ptr = 0;
	return (return_ptr);
}
