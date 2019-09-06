/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:12:32 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:12:36 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_lst_rev(t_list *lst)
{
	t_list *tail;
	t_list *head;
	t_list *temp;

	tail = NULL;
	head = lst;
	while (head != NULL)
	{
		temp = head->next;
		head->next = tail;
		tail = head;
		head = temp;
	}
	lst = tail;
	return (lst);
}
