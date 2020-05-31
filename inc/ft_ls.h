
#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <limits.h>

# define OPTIONS		(12)
# define MAX_PATH_LEN	(255)

# define ERR_LS_INVOPT	(-1)

/*
**	Mandatory Options
*/

# define OPT_L		(1 << 0)
# define OPT_1		(1 << 1)
# define OPT_R		(1 << 2)
# define OPT_CAPR	(1 << 3)
# define OPT_A		(1 << 4)
# define OPT_T		(1 << 5)

/*
**	Bonus Options
*/

# define OPT_CAPA	(1 << 6)
# define OPT_G		(1 << 7)
# define OPT_CAPG	(1 << 8)
# define OPT_D		(1 << 9)
# define OPT_U		(1 << 10)
# define OPT_CAPU	(1 << 11)



/*
**	Data structures
*/

typedef struct		s_option
{
	char	option;
	short	code;
}					t_option;

extern const t_option	g_options[];

typedef struct		s_path
{
	char			pathname[MAX_PATH_LEN + 1];
	DIR				*dp;
	struct dirent	*dir;
	struct stat		st;
	struct s_path	*next;
}					t_path;

typedef struct		s_ls
{
	int16_t			options;
	const char		*prog;
	t_path			*paths;
}					t_ls;

void	ft_ls_init(t_ls **ls, char **av);
void	get_cmdline_arguments(t_ls *ls, char **av);
void	ft_ls_get_path(t_ls *ls, char *arg);
void	print_paths(t_ls *ls);
void	ft_ls_terminate(t_ls *ls, int err);

#endif

