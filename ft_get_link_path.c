/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_link_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:26:57 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/08 18:27:37 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_link_path(char *path)
{
	char	result[256];
	ssize_t	ret;

	ret = readlink(path, result, 255);
	result[ret] = '\0';
	ft_putstr(result);
}
