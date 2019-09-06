/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:17:29 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:17:33 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char        *get_directory(t_list *list)
{
    struct stat info;
    char    *is_dir;
    
    while (list)
    {
        if (lstat(list->content, &info) == 0)
        {
            if (S_ISDIR(stats.st_mode))
            {
                is_dir = ft_strdup(list->content);
            }
        }
    }
}
