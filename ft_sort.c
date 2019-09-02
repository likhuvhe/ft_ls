/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:09:35 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/02 12:01:01 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_sort_list(t_list *lst, int (*compare)(void *, void *))
{
	t_list	*temp;
	void	*swap;

	temp = lst;
	while (lst->next != NULL)
	{
		if (((*compare)(lst->content, lst->next->content)) != 1)
		{
			swap = lst->next->content;
			lst->next->content = lst->content;
			lst->content = swap;
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}
