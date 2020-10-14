
#include "ft_ls.h"

void	free_paths(t_path *lst)
{
	t_path	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->pathname);
		free(tmp);
	}
}

void	ft_ls_terminate(t_ls *ls, int err)
{
	if (err > 0)
		ft_dprintf(STDERR, "%s: %s\n", ls->prog, strerror(err));
	free_paths(ls->paths);
	free_paths(ls->dirs);
	free_paths(ls->files);
	free(ls);
	exit(err);	
}
