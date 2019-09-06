/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:12:03 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/06 13:12:08 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	just_ls()
{
	t_list	*ls_list;
	t_list	*sort_ls;
	DIR		*current_dir;

	ls_list = NULL;
	current_dir = opendir(".");
	while ((r = readdir(current_dir)))
	{
		if(r->d_name[0] != '.')
			ft_lstadd(&ls_list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
	}
	sort_ls = ft_sort_list(ls_list, &compare);
	ft_lstiter(sort_ls, &display_list);
	closedir(current_dir);
}

static int	is_flag(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_list *parsed_lst;

	parsed_lst = NULL;
	if (argc == 2 && (ft_strcmp("--", argv[1])) == 0)
	{
		just_ls();
		return (0);
	}
	else if (argc > 1)
	{
		char	*flags;
		char	*final_flags;
		int		i;
		t_list	*sort_parsed;

		flags = ft_strdup("artRl");
		final_flags = ft_strnew(1);
		i = 1;
		sort_parsed = NULL;
		while (i < argc)
		{
			if (is_flag(argv[i][0]) == 1)
			{
				if (ft_strcmp("--", argv[i]) == 0 && argv[i + 1][0] == '-')
				{
					i++;
					break ;
				}
				if (i == 1)
					final_flags = ft_strcat(final_flags, argv[i]);
				else
					final_flags = ft_strcat(final_flags, argv[i] + 1);
			}
			else
				break ;
			i++;
		}
		if (i < argc)
		{
			parsed_lst = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
			while (++i < argc)
			{
				ft_lstadd(&parsed_lst, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
			}
			sort_parsed = ft_sort_list(parsed_lst, &compare);
		}
		//ft_putendl(final_flags);
		//ft_lstiter(sort_parsed, &display_list);
		//ft_putchar('\n');
		if (final_flags[0] != '\0' && sort_parsed == NULL)
			ls_with_flags(flags, final_flags);
		else
			print_parsed_f_d(sort_parsed, final_flags);
	}
	else
		just_ls();
	return (0);
}
