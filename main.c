
#include "ft_ls.h"

void	_swap(struct stat *a, struct stat *b)
{
	struct stat t;

	t = *a;
	*a = *b;
	*b = t;
}

int		main(int ac, char *av[])
{
	DIR				*d;
	struct dirent	*de;
	char			*s1 = "option.c";
	char			*s2 = "opt_map.c";

	ft_printf("mine: %d\n", ft_strcasecmp(s1, s2));
	ft_printf("lc:   %d\n", strcasecmp(s1, s2));
	return (0);
}
