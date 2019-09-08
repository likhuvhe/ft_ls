/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:52:23 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/08 17:53:13 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static int        has_slash(char *s, char c)
// {
//     while (*s)
//     {
//         if (*s == c)
//             return (1);
//         s++;
//     }
//     return (0);
// }
// char        *get_directory(t_list *list)
// {
//     struct stat info;
//     char    *is_dir;
//     while (list)
//     {
//         if (lstat(list->content, &info) == 0)
//         {
//             if (S_ISDIR(stats.st_mode))
//             {
//                 is_dir = ft_strdup(list->content);
//             }
//         }
//     }
// }

void	recurse(t_list *list, char *options)
{
	t_list	*lst;

	lst = NULL;
	while (list)
	{
		if (lstat(list->content, &stats) == 0)
		{
			if (S_ISDIR(stats.st_mode))
			{
				lst = creat_lst_dir(list->content, options);
				ft_finally_print(lst, options, list->content);
				ft_putchar('\n');
			}
		}
		list = list->next;
	}
	return ;
}
