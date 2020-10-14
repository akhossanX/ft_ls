
#include "ft_ls.h"

void	ft_ls_init(t_ls **ls, char **av)
{
	*ls = NULL;
	if (!(*ls = (t_ls *)ft_memalloc(sizeof(t_ls))))
		ft_ls_terminate(*ls, errno);
	if (ft_strstr(av[0], "./"))
		(*ls)->prog = &av[0][2];
	else
		(*ls)->prog = av[0];
	get_cmdline_arguments(*ls, av + 1);
}
