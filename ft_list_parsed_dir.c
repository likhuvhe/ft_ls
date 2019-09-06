/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsed_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:16:19 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:16:21 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*creat_lst_dir(char *directory, char *option)
{
	t_list	*ls_list;
	t_list	*sort_ls;
	DIR		*current_dir;
	size_t	len;

	ls_list = NULL;
	len = 0;
	current_dir = opendir(directory);
	if (is_option('a', option) == 0)
	{
		while ((r = readdir(current_dir)))
		{
			len = ft_strlen(r->d_name) + 1;
			if (r->d_name[0] != '.')
				ft_lstadd(&ls_list, ft_lstnew(r->d_name, len));
		}
	}
	else
	{
		while ((r = readdir(current_dir)))
			ft_lstadd(&ls_list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
	}
	sort_ls = ft_sort_list(ls_list, &compare);
	return (sort_ls);
	closedir(current_dir);
}
static int list_size(t_list *parsed_dir_lst)
{
	int size;

	size = 0;
	while (parsed_dir_lst != NULL)
	{
		parsed_dir_lst = parsed_dir_lst->next;
		size++;
	}
	return (size);
}

void	ft_list_parsed_dir(t_list *dir, char *flags)
{
	t_list *list;
	int size;

	size = list_size(dir);
	list = NULL;
	while (dir)
	{
		if (size > 1)
		{
			ft_putstr(dir->content);
			ft_putendl(":");
		}
		list = creat_lst_dir(dir->content, flags);
		ft_finally_print(list, flags, (char *)dir->content);
		ft_lstdel(&list, &del);
		if (dir->next != NULL)
			ft_putchar('\n');
		dir = dir->next;
	}
}