/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:27:00 by fmarckma          #+#    #+#             */
/*   Updated: 2019/07/23 15:40:04 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 int	ft_solution(char **g_map_rep,int **g_matrix_sol, t_map_chars pos)
{
	int i;
	int j;
	int value;

	value = 1;
	i = 0;
	while (g_map_rep[i])
	{ 
		j = 0;
		while (g_map_rep[i][j] != '\n')
		{
			if (g_map_rep[i][j] == pos.obstacle)
				g_matrix_sol[i][j] = 0;
			else if (i == 0 && g_map_rep[i][j] != pos.obstacle)
				g_matrix_sol[i][j] = value;
				ft_position(g_matrix_sol, i, j, value)
			j++;
		}
		i++;
	}
}

void	ft_position(char **g_matrix_sol, int i, int j, int value)
{
	int up;
	int left;

	left = j - 1;
	up = i - 1;
	if (g_matrix_sol[i][left] && g_matrix_sol[up][j]
		&& g_matrix_sol[up][left] == value)
	{
		g_matrix_sol[i][j] = value + 1;
	}
}
