/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:57:31 by atau              #+#    #+#             */
/*   Updated: 2019/09/02 12:04:39 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if ((s1[i] - s2[i]) < 0)
		return (-1);
	else if ((s1[i] - s2[i]) > 0)
		return (1);
	else
		return (0);
}
