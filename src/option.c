
#include "ft_ls.h"

static void	ft_ls_validate_flags(t_ls *ls, char *flags)
{
	int		i;
	int		valid;

	while (*(++flags))
	{
		i = 0;
		valid = 0;
		while (i < OPTIONS)
		{
			if (g_options[i].option == *flags)
			{
				ls->options |= g_options[i].code;
				valid = 1;
				break ;
			}
			i++;
		}
		if (!valid)
		{
			ft_dprintf(STDERR, "%s: invalid option -- '%c'\n", \
				ls->prog, *flags);
			ft_ls_terminate(ls, ERR_LS_INVOPT);
		}
	}
}

void	get_cmdline_arguments(t_ls *ls, char **av)
{
	int		i;
	int		opt_end;

	opt_end = INT_MAX;
	i = 0;
	while (av[i])
	{
		if (opt_end == INT_MAX && ft_strcmp(av[i], "--") == 0)
			opt_end = i;
		//else if (i < opt_end && ft_strncmp(av[i], "--", 2) == 0)
			//lookup_long_opt_table(cat, s[cat->i]);
		else if (i < opt_end && av[i][0] == '-' && av[i][1])
			ft_ls_validate_flags(ls, av[i]);
		else
			ft_ls_get_path(ls, av[i]);
		i += 1;
	}
	if (ls->paths == NULL)
		ft_ls_get_path(ls, ".");
}
