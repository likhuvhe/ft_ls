/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:17:03 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/17 18:17:07 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void     recurse_dir(char *path, char *flags)
{
    t_list *mylist;
    char    *newdir;
    DIR     *dp;

    newdir = 0;
    if ((dp = opendir(path)))
    {
        mylist = creat_lst_dir(path, flags);
        ft_putendl("\n");
        ft_putstr(path);
        ft_putendl(":");
        if (mylist)
        {
            ft_finally_print(mylist, flags, path);
            ft_lstdel(&mylist, &del);
        }
        while ((r = readdir(dp)))
        {
            if(ft_strncmp(r->d_name, ".", 1))
            {
                if ((is_option('R', flags) != 0) && r->d_type == 4)
                {
                    newdir = full_path(r->d_name, path);
                    recurse_dir(newdir, flags);
                    ft_strdel(&newdir);
                }
            }
            ft_strdel(&newdir);
        }
        closedir(dp);
    }
}

void        recurse(t_list *list, char *options, char *parsed_path)
{
    char    *path;

    if (parsed_path == NULL)
        parsed_path = ft_strdup(".");
    path = NULL;
    while (list)
    {
        if ((ft_strcmp(list->content, ".") != 0) && (ft_strcmp(list->content, "..") != 0))
            path = full_path(list->content, parsed_path);
        if (lstat(path, &stats) == 0)
            if (S_ISDIR(stats.st_mode) && S_ISLNK(stats.st_mode) == 0)
			{sleep(20);
                recurse_dir(path, options);sleep(20);
			}
        list = list->next;
        if (path)
            ft_strdel(&path);
    }
     ft_strdel(&parsed_path);
}
