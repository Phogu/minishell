/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukat <mbuyukat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:19:44 by mbuyukat          #+#    #+#             */
/*   Updated: 2023/11/14 07:19:44 by mbuyukat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	int sayi karakter dizisine cevrilir ve return edilir.
*/
char	*ft_itoa(int number)
{
	char	*ptr;
	int		len;
	int		temp_number;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (number == 0)
		return (ft_strdup("0"));
	temp_number = number;
	len = get_numbercount(temp_number);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (number < 0)
	{
		ptr[0] = '-';
		number *= -1;
	}
	ptr[len--] = 0;
	while (number)
	{
		ptr[len--] = '0' + (number % 10);
		number /= 10;
	}
	return (ptr);
}

/*
	bir sayinin kac basamakli oldugunu anlamamizi saglar.
*/
int	get_numbercount(int number)
{
	int	len;

	len = 0;
	if (number < 0)
	{
		len++;
	}
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}
