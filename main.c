/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:46:34 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/24 18:21:00 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

void			print_solution(void)
{
	int i;
	int j;

	i = 0;
	while (g_map_rep[i])
	{
		j = 0;
		while (g_map_rep[i][j])
			write(1, &g_map_rep[i][j++], 1);
		if (i == 0 || g_map_rep[i + 1])
			write(1, "\n", 1);
		if (g_map_rep[i + 1])
			free(g_map_rep[i]);
		i++;
	}
	free(g_map_rep);
}

int				search_solution(char *map_name, t_map_params params)
{
	t_map_chars map_chars;

	if (params.size == 0)
		map_chars = read_map(map_name);
	else
		map_chars = params.chars;
	if (map_chars.empty == '\0')
	{
		write(2, "map error\n", 10);
		return (0);
	}
	else
	{
		ft_fill(g_map_rep, g_matrix_sol, map_chars);
		print_solution();
		return (1);
	}
}

int				main(int argc, char **argv)
{
	int				i;
	t_map_params	params;

	params.size = 0;
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			search_solution(argv[i], params);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		read_stdin();
	}
	return (0);
}
