/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsed_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:30:44 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/18 18:18:03 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		index;

	index = 0;
	list = begin_list;
	while (list)
	{
		index++;
		list = list->next;
	}
	return (index);
}

static void	do_cap_r(t_list *list, char *flags, char *dir_conten)
{
	recurse(list, flags, dir_conten);
	if (is_option('r', flags) == 0)
		ft_lstdel(&list, &del);
}

void		ft_list_parsed_dir(t_list *dir, char *flags)
{
	t_list	*list;
	int		size;

	size = ft_list_size(dir);
	list = NULL;
	while (dir)
	{
		if (size > 1)
		{
			ft_putstr((char *)dir->content);
			ft_putendl(":");
		}
		list = creat_lst_dir((char *)dir->content, flags);
		if (list)
			ft_finally_print(list, flags, (char *)dir->content);
		ft_putchar('\n');
		if (is_option('R', flags) != 0)
			do_cap_r(list, flags, (char *)dir->content);
		if (dir->next != NULL)
			ft_putchar('\n');
		dir = dir->next;
	}
}
