/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:02:54 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/09 16:37:02 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	has_slash(char *s, char c)
{
	int len;

	len = ft_strlen(s) - 1;
	if (s[len] == c)
		return (1);
	return (0);
}

char		*full_path(char *content, char *path)
{
	char *path_content;
	char *temp;

	if (path != NULL)
	{
		if (has_slash(path, '/') == 0)
		{
			temp = ft_strjoin(path, "/");
			path_content = ft_strjoin(temp, content);
			free(temp);
		}
		else
			path_content = ft_strjoin(path, content);
	}
	else
		path_content = content;
	return (path_content);
}
