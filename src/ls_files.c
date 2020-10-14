
#include "ft_ls.h"

void	ft_ls_files(t_ls *ls)
{
	//if flag '-U' is enabled, do not sort (--sort=none)
	if ((ls->options & OPT_CAPU) == 0)
	{
		if (ls->options & OPT_R)
			ft_rsort(ls, &ls->files);
		else
			ft_sort(ls, &ls->files);
	}
	if (ls->options & OPT_L)
		long_list_format(ls->files);
	else if (ls->options & OPT_1)
		one_column_format(ls->files);
	else
		block_format(ls->files);
}
