/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:26:45 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/17 18:26:49 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*the_lst(char *option)
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

static void		put_total(t_list *list, char *s)
{
	int		total;
	char	*final_path;

	total = 0;
	while (list)
	{
		final_path = full_path(list->content, s);
		if ((lstat(final_path, &stats)) == 0)
			total += stats.st_blocks;
		list = list->next;
		ft_strdel(&final_path);
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

static void		print_l(t_list *list, char *s)
{
	t_list *head;
	char	*dot;

	if (s == NULL)
	{
		dot = ft_strdup(".");
		lstat(dot, &stats);
		if (S_ISDIR(stats.st_mode))
			put_total(list, dot);
		while (list)
		{
			long_ls((char *)list->content, dot);
			list = list->next;
		}
		ft_strdel(&dot);
	}
	else
	{
			lstat(s, &stats);
		if (S_ISDIR(stats.st_mode))
			put_total(list, s);
		while (list)
		{
			long_ls((char *)list->content, s);
			list = list->next;
		}
	}
}

static t_list	*ft_do_t_r(t_list *list, char *final_flags, char *dir_path)
{
	t_list *head;

	if (is_option('t', final_flags) != 0)
	{
		head = ft_sort_time(list, &ft_timecmp, dir_path);
		list = head;
	}
	if (is_option('r', final_flags) != 0)
	{
		head = ft_lst_rev(list);
		list = head;
	}
	return (list);
}

void			ft_finally_print(t_list *list, char *final_flags,\
		char *dir_path)
{
	if (list == NULL)
		list = the_lst(final_flags);
	if (list)
	{
		if (final_flags)
			list = ft_do_t_r(list, final_flags, dir_path);
		if (is_option('l', final_flags) != 0)
			print_l(list, dir_path);
		else
			ft_lstiter(list, &display_list);
		
	}
	if ((list && (is_option('R', final_flags) == 0)) || (!dir_path))
		ft_lstdel(&list, &del);
	if (dir_path && (is_option('R', final_flags) == 0))
		ft_strdel(&dir_path);
	
}
