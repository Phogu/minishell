/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrAddChar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:20:24 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:20:24 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	gonderilne dst dizisine c karakterini ekler. Eger dst'nin ici bos ise 
	sadece karakter eklenip, yaratilir.
	İslemlerden sonra eger onceden bir dst degeri var ise bu freelenir 
	ve ardindan yeni olusturulan dizi dst'ye atanir.
*/
void	str_addchar(char **dst, char c)
{
	char	*ptr;
	char	*holder_ptr;
	char	*holder_dst;
	int		len;

	len = ft_strlen(*dst) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	holder_ptr = ptr;
	holder_dst = *dst;
	while (holder_dst && *holder_dst)
		*(holder_ptr++) = *(holder_dst++);
	*(holder_ptr++) = c;
	*(holder_ptr++) = 0;
	if (*dst)
		free(*dst);
	*dst = ptr;
}
