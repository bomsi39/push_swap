/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:58:42 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/08 11:11:28 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstc;
	unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	if (!src && !dst)
		n = 0;
	while (0 < n)
	{
		*dstc = *srcc;
		dstc++;
		srcc++;
		n--;
	}
	return (dst);
}
