/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:21:58 by dfranke           #+#    #+#             */
/*   Updated: 2021/06/15 11:50:33 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}
