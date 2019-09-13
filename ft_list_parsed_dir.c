/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsed_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:16:19 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/13 13:52:47 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	list_size(t_list *parsed_dir_lst)
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

void		ft_list_parsed_dir(t_list *dir, char *flags)
{
	t_list	*list;
	int		size;

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
		if (dir->next != NULL)
			ft_putchar('\n');
		dir = dir->next;
	}
}
