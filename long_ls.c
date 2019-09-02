/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:10:06 by lkhuvhe           #+#    #+#             */
/*   Updated: 2019/09/02 11:10:08 by lkhuvhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		format(char *s, char c)
{
	ft_putstr(s);
	ft_putchar(c);
}

static void		permisions2(void)
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

static void		permisions1(void)
{
	if (S_ISDIR(stats.st_mode))
		ft_putchar('d');
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
}

void			long_ls(char *path)
{
	char **r;
	char *s;
	char *s1;

	if ((stat(path, &stats)) <= 0)
	{
		permisions1();
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
		format(path, '\n');
	}
}
