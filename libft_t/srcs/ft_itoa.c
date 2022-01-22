/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:20:23 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/08 13:00:22 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit(long int n)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*asc;
	long int	i;
	int			size;

	i = (long int)n;
	size = digit(i);
	asc = malloc(size + 1);
	if (!asc)
		return (NULL);
	asc[size] = '\0';
	if (i < 0)
	{
		i *= -1;
		asc[0] = '-';
	}
	if (i == 0)
		asc[0] = '0';
	while (0 < i)
	{
		asc[size - 1] = (i % 10) + 48;
		i /= 10;
		size--;
	}
	return (asc);
}
