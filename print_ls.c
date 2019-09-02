/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:12:46 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/02 13:44:10 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_option(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i] && c == 'a')
			return (1);
		if (c == str[i] && c == 'r')
			return (2);
		if (c == str[i] && c == 't')
			return (3);
		if (c == str[i] && c == 'l')
			return (4);
		if (c == str[i] && c == 'R')
			return (5);
		i++;
	}
	return (0);
}

static t_list		*the_lst(char *option)
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
	return (sort_ls);
	closedir(current_dir);
}

static void			print_l(t_list *list)
{
	while (list)
	{
		long_ls((char *)list->content);
		list = list->next;
	}

}

void				ft_finally_print(t_list *list, char *final_flags)
{
	t_list *head;

	if (list == NULL)
		list = the_lst(final_flags);
	if (list)
	{
		
		if (final_flags)
		{
			if (is_option('t', final_flags) != 0)
			{
				head = ft_sort_time(list, &ft_timecmp);
				list = head;
			}
			if (is_option('r', final_flags) != 0)
			{
				head = ft_lst_rev(list);
				list = head;
			}
			if (is_option('R', final_flags) != 0)
				ft_putchar('R');
		}
		if (is_option('l', final_flags) != 0)
			print_l(list);
		else
			ft_lstiter(list, &display_list);
	}
}
