
#include "ft_ls.h"

void	ft_ls_init(t_ls **ls, char **av)
{
	if (!(*ls = (t_ls *)ft_memalloc(sizeof(t_ls))))
		ft_ls_terminate(*ls, errno);
	(*ls)->prog = av[0];
	get_cmdline_arguments(*ls, av + 1);
}
