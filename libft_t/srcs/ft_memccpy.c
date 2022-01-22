/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:53:01 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/16 21:38:13 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstc;
	unsigned char		*srcc;
	size_t				i;

	i = 0;
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		if (srcc[i] == (unsigned char)c)
		{
			dstc[i] = srcc[i];
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
