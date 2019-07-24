/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:46:34 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/24 14:02:01 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	print_solution(void)
{
	int i;
	int j;

	i = 0;
	while (g_map_rep[i])
	{
		j = 0;
		while (g_map_rep[i][j])
			write(1, &g_map_rep[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int			i;
	t_map_chars	map_chars;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			map_chars = read_map(argv[i]);
			if (map_chars.empty == '\0')
			{
				write(2, "map error\n", 10);
			}
			else
			{
				print_solution();
			}
			i++;
		}
	}
}
