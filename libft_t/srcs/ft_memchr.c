/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:03:36 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/16 12:37:30 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	tc;
	unsigned int	i;

	ts = (unsigned char *)s;
	tc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ts[i] == tc)
			return (ts + i);
		i++;
	}
	return (NULL);
}
