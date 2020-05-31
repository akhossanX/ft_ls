
#include "ft_ls.h"

int		main(int ac, char *av[])
{
	t_ls	*ls;
	t_path	*tmp;

	(void)ac;
	ft_ls_init(&ls, av);
	print_paths(ls);
	ft_printf("=======================\n");
	tmp = ls->paths;	
	while (tmp)
	{
		tmp->dp = opendir(tmp->pathname);
		if (!tmp->dp && errno)
		{
			if (errno == EACCES || errno == ENOENT)
				ft_dprintf(STDERR, "%s: %s: %s\n", av[0], \
					tmp->pathname, strerror(errno));
		}
		closedir(tmp->dp);
		tmp = tmp->next;
	}
	ft_printf("flag: %#016b\n", ls->options);
	ft_ls_terminate(ls, 0);
	return (0);
}
