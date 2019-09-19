/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_lst_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:14:28 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/19 15:41:05 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		error(char *directory)
{
	ft_putstr("ft_ls: ");
	perror(directory);
}

static t_list	*ret_close(DIR *current_dir, t_list *ls_list)
{
	t_list *sort_ls;

	sort_ls = lst_sort_ascii(ls_list);
	closedir(current_dir);
	return (sort_ls);
}

t_list			*creat_lst_dir(char *directory, char *option)
{
	t_list	*ls_list;
	t_list	*sort_ls;
	DIR		*current_dir;
	size_t	len;

	ls_list = NULL;
	len = 0;
	if ((current_dir = opendir(directory)))
	{
		if (is_option('a', option) == 0)
			while ((r = readdir(current_dir)))
			{
				len = ft_strlen(r->d_name) + 1;
				if (r->d_name[0] != '.')
					ft_lstadd(&ls_list, ft_lstnew(r->d_name, len));
			}
		else
			while ((r = readdir(current_dir)))
				ft_lstadd(&ls_list, ft_lstnew(r->d_name, \
							ft_strlen(r->d_name) + 1));
		sort_ls = ret_close(current_dir, ls_list);
		return (sort_ls);
	}
	perror(directory);
	return (0);
}
