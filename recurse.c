/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:52:23 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/09 16:51:09 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurse(t_list *list, char *options, char *path)
{
	t_list	*lst;
	char	*final_path;
	char	*directory;

	if (path == NULL)
		path = ft_strdup(".");
	lst = NULL;
	while (list)
	{
		final_path = full_path(list->content, path);
		if (lstat(final_path, &stats) == 0)
		{
			if (S_ISDIR(stats.st_mode))
			{
				ft_putstr(list->content);
				ft_putendl(":");
				lst = creat_lst_dir(final_path, options);
				ft_finally_print(lst, options, final_path);
			}
		}
		list = list->next;
		free(path);
	}
	return ;
}