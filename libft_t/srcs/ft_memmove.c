/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:06:29 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/15 14:02:00 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dstc;
	unsigned char		*srcc;
	size_t				i;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (srcc < dstc)
	{
		while (0 < n)
		{
			n--;
			dstc[n] = srcc[n];
		}
		return (dst);
	}
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
