
#include "ft_ls.h"

void	free_paths(t_ls *ls)
{
	t_path	*p;
	t_path	*tmp;

	p = ls->paths;
	while (p)
	{
		tmp = p->next;
		free(p);	
		p = tmp;
	}
}

void	ft_ls_terminate(t_ls *ls, int err)
{
	if (err > 0)
		ft_dprintf(STDERR, "%s: %s\n", ls->prog, strerror(err));
	free_paths(ls);
	free(ls);
	exit(err);	
}
