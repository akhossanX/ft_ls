
#include "ft_ls.h"

int		ls_alphacmp(t_path *a, t_path *b, int flg)
{
	(void)flg;
	return (-ft_strcmp(a->pathname, b->pathname));
}

int		ls_nbcmp(t_path *a, t_path *b, int flg)
{
	struct stat	sa;
	struct stat	sb;
	int			ret;

	if (lstat(a->pathname, &sa) == -1 || lstat(b->pathname, &sb) == -1)
		perror("stat");
	if (flg & OPT_T)
	{
		ret = (sa.st_mtim.tv_sec - sb.st_mtim.tv_sec);
		if (ret == 0)
			return (ls_alphacmp(a, b, flg));
		return (ret);
	}
	else if (flg & OPT_CAPS)
	{
		ret = (sa.st_size - sb.st_size);
		if (ret == 0)
			return (ls_alphacmp(a, b, flg));
		return (ret);
	}
	return (0);
}

t_path	*find_middle_list(t_path *lst)
{
	t_path	*middle;
	t_path	*midnext;

	middle = lst;
	midnext = lst;
	while (midnext)
	{
		if (midnext->next)
		{
			midnext = midnext->next;
			if (midnext->next)
			{
				midnext = midnext->next;
				middle = middle->next;
			}
		}
		else
			midnext = midnext->next;
	}
	return (middle);
}

t_path	*merge_list(t_path *left, t_path *rigth, t_ls *ls)
{
	t_path	*m;
	t_path	*last;
	int		test;

	if (left == NULL || rigth == NULL)
		return (!left ? rigth : left);
	m = NULL;
	last = NULL;
	while (left && rigth)
	{
		test = ls->cmp(left, rigth, ls->options);
		ft_printf("{%s, %s, %d}\n", left->pathname, rigth->pathname, test);
		ls->options & OPT_R ? test *= -1 : 0;
		if (test > 0)
		{
			if (m == NULL)
				m = left;
			else
				last->next = left;
			last = left;
			left = left->next;
		}
		else
		{
			if (m == NULL)
				m = rigth;
			else
				last->next = rigth;
			last = rigth;
			rigth = rigth->next;
		}
	}
	last->next = (left == NULL) ? rigth : left;
	return (m);
}

t_path	*merge_sort(t_path *lst, t_ls *data)
{
	t_path	*middle;
	t_path	*midnext;
	t_path	*left;
	t_path	*rigth;

	if (lst == NULL || lst->next == NULL)
		return (lst);	
	middle = find_middle_list(lst);	
	midnext = middle->next;
	middle->next = NULL;
	left = merge_sort(lst, data);
	rigth = merge_sort(midnext, data);
	return (merge_list(left, rigth, data));
}

void	ft_sort(t_ls *ls, t_path **lst)
{
	if ((ls->options & OPT_T) || (ls->options & OPT_CAPS))
		ls->cmp = ls_nbcmp;
	else
		ls->cmp = ls_alphacmp;
	*lst = merge_sort(*lst, ls);
}

void	ft_rsort(t_ls *ls, t_path **lst)
{
	(void)ls;
	(void)lst;
}
