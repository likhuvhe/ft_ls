/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:18:16 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:18:18 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_option(char c, char *str)
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
