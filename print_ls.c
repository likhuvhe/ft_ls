/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:14:24 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:14:33 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static int			is_option(char c, char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (c == str[i] && c == 'a')
// 			return (1);
// 		if (c == str[i] && c == 'r')
// 			return (2);
// 		if (c == str[i] && c == 't')
// 			return (3);
// 		if (c == str[i] && c == 'l')
// 			return (4);
// 		if (c == str[i] && c == 'R')
// 			return (5);
// 		i++;
// 	}
// 	return (0);
// }

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

static char			*full_path(char *content, char *path)
{
	char *path_content;
	char *temp;

	if (path != NULL)
	{
		temp = ft_strjoin(path, "/");
		path_content = ft_strjoin(temp, content);
		free(temp);
	}
	else
		path_content = content;
	return (path_content);
}

static void			print_l(t_list *list, char *s)
{
	int total;
	t_list *head;
	char *final_path;
	
	total = 0;
	head = list;
	//if (s == NULL)
	//	s = ft_strdup(".");
	lstat(s, &stats);
	if(S_ISDIR(stats.st_mode))
	{
		while (list)
		{
			final_path = full_path(list->content, s);
			ft_putendl(final_path);
			if ((lstat(final_path, &stats)) == 0)
				total += stats.st_blocks;
			else if (s == NULL && lstat(list->content, &stats))
				total += stats.st_blocks;
			list = list->next;
		}
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
	list = head;
	while (list)
	{
		
		long_ls((char *)list->content, s);
		list = list->next;
	}
	ft_strdel(&s);
}

void				ft_finally_print(t_list *list, char *final_flags, char *dir_path)
{
	t_list *head;
	// ft_lstiter(list, &display_list);
	// ft_putchar('\n');

	if (list == NULL)
		list = the_lst(final_flags);
	if (list)
	{
		if (final_flags)
		{
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
		}
		if (is_option('l', final_flags) != 0)
			print_l(list, dir_path);
		else
			ft_lstiter(list, &display_list);
		//if (is_option('R', final_flags) != 0)
		//{
		//	char *path;
		//	path = get_directory(list);
		//	ft_recurse(path);
		//}
	}
}
