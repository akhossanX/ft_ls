
#include "ft_ls.h"

void	ft_ls_get_entries(t_ls *ls)
{
	t_path	*ptr;
	DIR		*dir;

	ptr = ls->paths;				
	while (ptr)
	{
		errno = 0;
		dir = opendir(ptr->pathname);
		if (dir == NULL && errno)
		{
			if (errno == ENOTDIR)
				ft_ls_get_path(ls, &ls->files, ptr->pathname);	
			else
				ft_dprintf(STDERR, "%s: %s: %s\n", ls->prog, \
					ptr->pathname, strerror(errno));
		}
		else
			ft_ls_get_path(ls, &ls->dirs, ptr->pathname);
		closedir(dir);
		ptr = ptr->next;
	}
}

int		main(int ac, char *av[])
{
	t_ls	*ls;

	(void)ac;
	ft_ls_init(&ls, av);
	ft_ls_get_entries(ls);
	ft_ls_files(ls);
	ft_ls_dirs(ls);
	ft_printf("flag: %#018b\n", ls->options);
	ft_ls_terminate(ls, 0);
	return (0);
}
