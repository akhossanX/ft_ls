
#include "ft_ls.h"


void	long_list_format(t_path *p)
{
	struct stat	st;
	char		*base;

	while (p)
	{
		lstat(p->pathname, &st);
		switch (st.st_mode & S_IFMT)
		{
			case (S_IFSOCK):	ft_printf("s"); break ;
			case (S_IFLNK) :	ft_printf("l"); break ;
			case (S_IFREG) :	ft_printf("-"); break ;
			case (S_IFBLK) :	ft_printf("b"); break ;
			case (S_IFDIR) :	ft_printf("d"); break ;
			case (S_IFCHR) :	ft_printf("c"); break ;
			case (S_IFIFO) :	ft_printf("p"); break ;
			default :			break ;
		}
		(st.st_mode & S_IRUSR) ? ft_printf("r") : ft_printf("-"); 
		(st.st_mode & S_IWUSR) ? ft_printf("w") : ft_printf("-");
		(st.st_mode & S_IXUSR) ? ft_printf("x") : ft_printf("-");
		(st.st_mode & S_IRGRP) ? ft_printf("r") : ft_printf("-");
		(st.st_mode & S_IWGRP) ? ft_printf("w") : ft_printf("-");
		(st.st_mode & S_IXGRP) ? ft_printf("x") : ft_printf("-");
		(st.st_mode & S_IROTH) ? ft_printf("r") : ft_printf("-");
		(st.st_mode & S_IWOTH) ? ft_printf("w") : ft_printf("-");
		(st.st_mode & S_IXOTH) ? ft_printf("x") : ft_printf("-");
		ft_printf("%2ld ", st.st_nlink);
		ft_printf("%-10s", getpwuid(st.st_uid)->pw_name);
		ft_printf("%-10s", getgrgid(st.st_gid)->gr_name);
		ft_printf("%5ld ", st.st_size);
		base = ft_strrchr(p->pathname, '/');
		ft_printf("%s\n", base ? base + 1 : p->pathname);
		p = p->next;
	}
}

void	one_column_format(t_path *p)
{
	char	*base;

	while (p)
	{
		base = ft_strrchr(p->pathname, '/');
		ft_printf("%s\n", base ? base + 1 : p->pathname);
		p = p->next;
	}
}

void	block_format(t_path *p)
{
	char	*base;

	//temporary config
	while (p)
	{
		base = ft_strrchr(p->pathname, '/');
		ft_printf("%s", base ? base + 1 : p->pathname);
		p = p->next;
		if (p)
			ft_printf("  ");
	}
	ft_printf("%c", '\n');
}

void	display_entries(t_ls *ls, t_path *lst)
{
	if (ls->options & OPT_L)
		long_list_format(lst);
	else if (ls->options & OPT_1)
		one_column_format(lst);
	else
		block_format(lst);
}
