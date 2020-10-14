
#include "ft_ls.h"

#define LS_RECURSIVE	(ls->options & OPT_CAPR)

/*


	1: open the dir;
	2: readdir and add all entries to a list of paths
	3: sort the entries list according to sort flags
	4: display entries	
	5: for each entry:
		if it is directory: goto: 1
		else
			next entry;

*/

char	*make_path(const char *p1, const char *p2)
{
	char	*s;
	char	*tmp;

	s = ft_strjoin(p1, "/");
	tmp = s;
	s = ft_strjoin(s, p2);
	free(tmp);
	return (s);
}

void	ft_ls_dir(t_ls *ls, const char *pathname)
{
	DIR				*dir;
	struct dirent	*ent;
	t_path			*lst;
	t_path			*tmp;
	char			*path;

	errno = 0;
	dir = opendir(pathname);
	if (dir == NULL)
	{
		// report all errors except when the entry is not a directory
		if (errno != ENOTDIR)
			ft_dprintf(STDERR, "%s: %s: %s\n", ls->prog, pathname, \
				strerror(errno));
		return ;
	}
	lst = NULL;
	while ((ent = readdir(dir)) != NULL)
	{
		ft_printf("pathname: %s\n", ent->d_name);
		if (!ft_strcmp(ent->d_name, "."))
			path = ft_strdup(".");
		else if (!ft_strcmp(ent->d_name, ".."))
			path = ft_strdup("..");
		else
			path = make_path(pathname, ent->d_name);
		ft_ls_get_path(ls, &lst, path);
		free(path);
	}
	//ft_printf("*********** SAVED PATHS: **********\n");
	//print_paths(lst);	
	if (ent == NULL && errno)
	{
		free_paths(lst);
		ft_ls_terminate(ls, errno);
	}
	closedir(dir);
	ft_sort(ls, &lst);
	ft_printf("\n{red}%s{eoc}:\n", pathname);
	display_entries(ls, lst);
	if (LS_RECURSIVE)
	{
		tmp = lst;
		while (tmp)
		{
			if (ft_strcmp(tmp->pathname, ".") != 0 && \
				ft_strcmp(tmp->pathname, "..") != 0)
				ft_ls_dir(ls, tmp->pathname);
			tmp = tmp->next;
		}
	}
	free_paths(lst);
}

void	ft_ls_dirs(t_ls *ls)
{
	t_path	*ptr;

	if ((ls->options & OPT_CAPU) == 0)
	{
		if (ls->options & OPT_R)
			ft_rsort(ls, &ls->dirs);
		else
			ft_sort(ls, &ls->dirs);
	}
	ptr = ls->dirs;
	if (ls->options & OPT_D)
	{
		display_entries(ls, ptr);
		return ;
	}
	while (ptr)
	{
		ft_ls_dir(ls, ptr->pathname);
		ptr = ptr->next;
	}
}
