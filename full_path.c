/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:02:54 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/08 14:04:53 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*full_path(char *content, char *path)
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
