/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsed_f_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:14:24 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/02 11:36:04 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_parsed_f_d(t_list *lst, char *flags)
{
	t_list *dir;
	t_list *files;
	t_list *temp;
	t_list *unwanted;
	t_list *sorted_lst;

	dir = NULL;
	files = NULL;
	temp = NULL;
	while (lst)
	{
		if ((stat(lst->content, &stats)) == 0)
		{
			if (S_ISDIR(stats.st_mode))
				ft_lstadd(&dir, ft_lstnew(lst->content, ft_strlen(lst->content) + 1));
			if (S_ISREG(stats.st_mode))
				ft_lstadd(&files, ft_lstnew(lst->content, ft_strlen(lst->content) + 1));
		}
		else
		{
			unwanted = NULL;
			ft_lstadd(&unwanted, ft_lstnew(lst->content, ft_strlen(lst->content) + 1));
			sorted_lst = ft_sort_list(unwanted, &compare);
			while (sorted_lst)
			{
				ft_putstr("ft_ls: ");
				ft_putstr(sorted_lst->content);
				ft_putendl(": No such file or directory");
				sorted_lst = sorted_lst->next;
			}
		}
		lst = lst->next;
	}
	if (files != NULL)
		ft_finally_print(files, flags);
	if (dir != NULL)
	{
		temp = ft_sort_list(dir, &compare);
		ft_list_parsed_dir(temp, flags);
	}
}
