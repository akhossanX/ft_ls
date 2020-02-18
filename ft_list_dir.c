/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:49 by akhossan          #+#    #+#             */
/*   Updated: 2020/02/18 15:08:24 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define STDERR	(2)
#define STDOUT	(1)
#define STDIN	(0)

typedef struct dirent	DIRENT;
extern int		errno;

int		main(int ac, char **av)
{
	DIR		*dir;
	char	*err;
	DIRENT	*dp;

	if (ac < 2)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
	if (dir == NULL)
	{
		err = strerror(errno);
		write(STDERR, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	while (dir)
	{
		if ((dp = readdir(dir)))
		{
			if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
			{
				write(STDOUT, dp->d_name, strlen(dp->d_name));
				write(STDOUT, "\n", 1);
			}
		}
		else
		{
			closedir(dir);
			dir = NULL;
		}
	}
	return (0);
}
