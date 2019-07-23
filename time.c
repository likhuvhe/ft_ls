#include <time.h>
#include <stdio.h>
#include "libft/libft.h"
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>


int main(void)
{
	char *s;
	//int i;
	struct passwd *user;
	struct stat stats;
	struct group *grp;
	//time(&s);
	//DIR *dir = opendir(".");
	//struct dirent *read = readdir(dir);
	if (stat(".", &stats) != -1)
	{
		// permisions
		if (S_ISDIR(stats.st_mode))
			ft_putchar('d');
		else
			ft_putchar('-');
		// hard links
		ft_putnbr(stats.st_nlink);
		ft_putchar(' ');
		// usename
		user = getpwuid(stats.st_uid);
		ft_putstr(user->pw_name);
		ft_putchar(' ');
		//group name
		grp = getgrgid(stats.st_gid);
		ft_putstr(grp->gr_name);
		ft_putchar(' ');
		// size in bytes
		ft_putnbr(stats.st_size);
		ft_putchar(' ');
		//time - date
		s = ft_strdup(ctime(&stats.st_mtime));
	char *s1 = ft_strsub(s, 4, 12);
	char **r = ft_strsplit(s1, ' ');
		ft_putstr(r[1]);
		ft_putchar(' ');
		ft_putstr(r[0]);
		ft_putchar(' ');
		ft_putstr(r[2]);
	//	printf("%lld\n", stats.st_size);
	
	}

	//char *t = ctime(&s);
	//char *str = ft_strsub(t, 4, 12);
	//char **s1 = ft_strsplit(str, ' ');
	//printf("%s\n", t );
	return 0;
}
