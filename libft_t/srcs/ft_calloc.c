/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:28 by dfranke           #+#    #+#             */
/*   Updated: 2021/05/27 14:12:13 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*abc;

	abc = malloc(count * size);
	if (!abc)
		return (NULL);
	ft_bzero(abc, count * size);
	return (abc);
}
