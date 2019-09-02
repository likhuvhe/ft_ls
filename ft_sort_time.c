/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:11:44 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/02 11:11:48 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_time(char *file_a, char *file_b, struct timespec *a,\
		struct timespec *b)
{
	struct stat		info;

	lstat(file_a, &info);
	*a = info.st_mtimespec;
	lstat(file_b, &info);
	*b = info.st_mtimespec;
}

t_list			*ft_sort_time(t_list *lst,\
		int (*time_compare)(struct timespec *, struct timespec *))
{
	t_list			*temp;
	void			*swap;
	struct timespec	time_a;
	struct timespec	time_b;

	temp = lst;
	while (lst->next != NULL)
	{
		set_time(lst->content, lst->next->content, &time_a, &time_b);
		if (((*time_compare)(&time_a, &time_b)) == -1)
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
