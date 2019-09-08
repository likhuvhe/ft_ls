/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:18:38 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/08 18:29:15 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	format(char *s, char c)
{
	ft_putstr(s);
	ft_putchar(c);
}

static void	permisions2(void)
{
	if (stats.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void	permisions1(char *path)
{
	if (S_ISDIR(stats.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(stats.st_mode))
		ft_putchar('l');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	permisions2();
	get_exattr(path);
}


void		long_ls(char *path, char *dir_path)
{
	char **r;
	char *s;
	char *s1;
	char *path_content;

	path_content = full_path(path, dir_path);
	if ((lstat(path_content, &stats)) == 0)
	{
		permisions1(path_content);
		ft_putchar(' ');
		ft_putnbr(stats.st_nlink);
		ft_putchar(' ');
		user = getpwuid(stats.st_uid);
		format(user->pw_name, ' ');
		grp = getgrgid(stats.st_gid);
		format(grp->gr_name, ' ');
		ft_putnbr(stats.st_size);
		ft_putchar(' ');
		s = ft_strdup(ctime(&stats.st_mtime));
		s1 = ft_strsub(s, 4, 12);
		r = ft_strsplit(s1, ' ');
		format(r[1], ' ');
		format(r[0], ' ');
		format(r[2], ' ');
		ft_putstr(path);
		if (S_ISLNK(stats.st_mode))
		{
			ft_putstr(" -> ");
			ft_get_link_path(path_content);
		}
		ft_putchar('\n');
	}
}
