/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:27:00 by fmarckma          #+#    #+#             */
/*   Updated: 2019/07/23 22:00:48 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_solution(char **g_map_rep,int **g_matrix_sol, t_map_chars pos)
{
	int i;
	int j;

	i = 0;
	while (g_map_rep[i])
	{ 
		j = 0;
		while (g_map_rep[i][j] != '\n')
		{
			if (g_map_rep[i][j] == pos.obstacle)
				g_matrix_sol[i][j] = 0;
			else if (i == 0 && g_map_rep[i][j] != pos.obstacle)
				g_matrix_sol[i][j] = 1;
			else if (g_map_rep[i][j] != pos.obstacle)
				g_matrix_sol[i][j] = 1;
			ft_position(g_matrix_sol, i, j)
			j++;
		}
		i++;
	}
}

void	ft_position(char **g_matrix_sol, int i, int j)
{
	int 		up;
	int 		left;
	t_pos_map	save;

	save.value = 0;
	left = j - 1;
	up = i - 1;
	if (j > 1 && i > 1)
	{
		if ((g_matrix_sol[i][left] == g_matrix_sol[i][j]) && (g_matrix_sol[up][j]
			== g_matrix_sol[i][j]) && (g_matrix_sol[up][left] == g_matrix_sol[i][j]))
		{
			g_matrix_sol[i][j] += 1;
			if (g_matrix_sol[i][j] > save.value)
			{
				save.x = j;
				save.y = i;
				save.value = g_matrix_sol[i][j];
			}
		}
	}
}	
