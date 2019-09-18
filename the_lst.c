/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:18:31 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/18 18:18:35 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*the_lst(char *option)
{
	t_list	*ls_list;
	t_list	*sort_ls;
	DIR		*current_dir;
	size_t	len;

	ls_list = NULL;
	len = 0;
	current_dir = opendir(".");
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
	closedir(current_dir);
	return (sort_ls);
}
