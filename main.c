/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:46:34 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/23 15:28:33 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		main(int argc, char **argv)
{
	int			i;
	int			j;
	int			k;
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
				j = 0;
				while (g_map_rep[j])
				{
					k = 0;
					while (g_map_rep[j][k])
						write(1, &g_map_rep[j][k++], 1);
					write(1, "\n", 1);
					j++;
				}
			}
			i++;
		}
	}
}
