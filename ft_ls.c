/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:12:03 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/13 13:57:07 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_flag(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

static char	*do_option(char *final_flags, int ac, int i, char **av)
{
	char *temp;

	while (i < ac)
	{
		if (is_flag(av[i][0]) == 1)
		{
			temp = final_flags;
			if (ft_strcmp("--", av[i]) == 0 && av[i + 1][0] == '-')
			{
				i++;
				break ;
			}
			final_flags = (i == 1) ? ft_strjoin(final_flags, av[i]) : \
				ft_strjoin(final_flags, av[i] + 1);
			ft_strdel(&temp);
		}
		else
			break ;
		i++;
	}
	return (final_flags);
}

static int	i_count(char *final_flags, int ac, int i, char **av)
{
	char *temp;

	final_flags = ft_strnew(0);
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '\0')
			break ;
		if (is_flag(av[i][0]) == 1)
		{
			temp = final_flags;
			if (ft_strcmp("--", av[i]) == 0 && av[i + 1][0] == '-')
			{
				i++;
				break ;
			}
			final_flags = (i == 1) ? ft_strjoin(final_flags, av[i]) : \
				ft_strjoin(final_flags, av[i] + 1);
			ft_strdel(&temp);
		}
		else
			break ;
		i++;
	}
	ft_strdel(&final_flags);
	return (i);
}

static void	do_ft_ls(int argc, int i, char *final_flags, char **argv)
{
	t_list	*parsed_lst;
	char	*flags;
	t_list	*sort_parsed;

	parsed_lst = NULL;
	flags = ft_strdup("artRl");
	final_flags = ft_strnew(0);
	i = 1;
	sort_parsed = NULL;
	final_flags = do_option(final_flags, argc, i, argv);
	i = i_count(final_flags, argc, i, argv);
	if (i < argc)
	{
		parsed_lst = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
		while (++i < argc)
			ft_lstadd(&parsed_lst, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		sort_parsed = ft_sort_list(parsed_lst, &compare);
	}
	(final_flags[0] != '\0' && sort_parsed == NULL) ? ls_with_flags(flags, \
			final_flags) : print_parsed_f_d(sort_parsed, final_flags);
	ft_lstdel(&sort_parsed, &del);
	ft_strdel(&flags);
	ft_strdel(&final_flags);
}

int			main(int argc, char **argv)
{
	char	*final_flags;
	int		i;

	if (argc == 2 && (ft_strcmp("--", argv[1])) == 0)
	{
		just_ls();
		return (0);
	}
	else if (argc > 1)
		do_ft_ls(argc, i, final_flags, argv);
	else
		just_ls();
		sleep(40);
	return (0);
}