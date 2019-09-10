/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:18:02 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/08 16:06:36 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_the_path(char *parent, char *con)
{
	char *s1;
	char *temp;

	if (parent != NULL)
	{
		temp = ft_strjoin(parent, "/");
		s1 = ft_strjoin(temp, con);
		free(temp);
		return (s1);
	}
	return (con);
}

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
		int (*time_compare)(struct timespec *, struct timespec *), char *path)
{
	t_list	*temp;
	void	*swap;
	char	*con;
	char	*con_next;

	temp = lst;
	while (lst->next != NULL)
	{
		con = get_the_path(path, (char *)lst->content);
		con_next = get_the_path(path, (char *)lst->next->content);
		set_time(con, con_next, &time_a, &time_b);
		if (((*time_compare)(&time_a, &time_b)) == -1)
		{
			swap = lst->next->content;
			lst->next->content = lst->content;
			lst->content = swap;
			lst = temp;
		}
		else
			lst = lst->next;
		if (path != NULL)
		{
			ft_strdel(&con);
			ft_strdel(&con_next);
		}
	}
	lst = temp;
	return (lst);
}
