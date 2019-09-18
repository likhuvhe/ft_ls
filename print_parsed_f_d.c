/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsed_f_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:39:12 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/18 16:42:13 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_files_dir_error(char *s)
{
	t_list	*sorted_lst;
	t_list	*s2;

	sorted_lst = NULL;
	s2 = NULL;
	ft_lstadd(&s2, ft_lstnew(s, ft_strlen(s) + 1));
	sorted_lst = ft_sort_list(s2, &compare);
	while (sorted_lst)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(sorted_lst->content);
		ft_putendl(": No such file or directory");
		sorted_lst = sorted_lst->next;
	}
	ft_lstdel(&s2, &del);
}

static void		ft_do_directories(t_list *directory, char *flags)
{
	t_list *temp;

	temp = NULL;
	temp = ft_sort_list(directory, &compare);
	ft_list_parsed_dir(temp, flags);
	while (temp)
	{
		free(temp);
		temp = temp->next;
	}
	temp = NULL;
}

void			print_parsed_f_d(t_list *lst, char *flags)
{
	t_list *dir;
	t_list *files;
	t_list *sorted_lst;

	dir = NULL;
	files = NULL;
	while (lst)
	{
		if ((lstat(lst->content, &stats)) == 0)
		{
			if (S_ISDIR(stats.st_mode))
				ft_lstadd(&dir, ft_lstnew(lst->content,\
							ft_strlen(lst->content) + 1));
			if (S_ISREG(stats.st_mode))
				ft_lstadd(&files, ft_lstnew(lst->content,\
							ft_strlen(lst->content) + 1));
		}
		else
			ft_files_dir_error(lst->content);
		lst = lst->next;
	}
	if (files != NULL)
		ft_finally_print(files, flags, NULL);
	if (dir != NULL)
		ft_do_directories(dir, flags);
}
