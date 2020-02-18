/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   national_project.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:39:49 by akhossan          #+#    #+#             */
/*   Updated: 2020/02/17 17:41:47 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>

using namespace std;

void	get_variables(char *s, int *n, int *g, int *b)
{
	*n = std::atoi(s);
	*g = std::atoi(s = strchr(s, ' '));	
	*b = std::atoi(strchr(s, ' '));	
}

void	min_days(string str)
{
	int				n;
	int				g;
	int				b;
	char			*s;

	s = (char *)str.c_str();	
	get_variables(s, &n, &g, &b);
	//cout << n << " " << g << " " << b << endl;
	for (int i = 0; i < n, i++)
	{
		if (i <= n / 2)
		{
				
		}
	}	
}

int		main(int ac, char *argv[])
{
	string	data;
	int		tests;

	getline(cin, data);
	if ((tests = std::stoi(data)) <= 0)
		return (1);
	for (int i = 0; i < tests; i++)
	{
		getline(cin, data);
		min_days(data);
	}
	return (0);
}
