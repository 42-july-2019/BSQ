/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:27:00 by fmarckma          #+#    #+#             */
/*   Updated: 2019/07/24 13:54:40 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fill(char **g_map_rep,int **g_matrix_sol, t_map_chars pos)
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

void	ft_position(int **g_matrix_sol, int i, int j)
{
	int 		up;
	int 		left;
	t_pos_map	save;

	save.value = 0;
	left = j - 1;
	up = i - 1;
	if (j > 1 && i > 1)
	{
		if (((g_matrix_sol[up][left] == g_matrix_sol[up][j]) || (g_matrix_sol[up][left]
			== g_matrix_sol[i][left]) || g_matrix_sol[up][j] == g_matrix_sol[i][left]) 
				&& (g_matrix_sol[i][j] != 0))
		{
			g_matrix_sol[i][j] +=  1;
			if (g_matrix_sol[i][j] > save.value)
			{
				save.x = j;
				save.y = i;
				save.value = g_matrix_sol[i][j];
			}
		}
	}
}

void	verif_all(int **g_matrix_sol, t_pos_map save)
{
	int j;
	int i;
	
	i = 0;
	j = 0;
	while (g_matrix_sol[i])
	{
		while (g_matrix_sol[i][j] != '\n')
		{
			if (j > 1 && i > 1)
			{
				if (((g_matrix_sol[up][left] == g_matrix_sol[up][j]) || (g_matrix_sol[up][left]
					== g_matrix_sol[i][left]) || g_matrix_sol[up][j] == g_matrix_sol[i][left]) 
					&& (g_matrix_sol[i][j] != 0))
				{
					g_matrix_sol[i][j] +=  1;
					if (g_matrix_sol[i][j] > save.value)
					{
						save.x = j;
						save.y = i;
						save.value = g_matrix_sol[i][j];
					}
				}
			}
			j++;
		}
		i++;
	}
}

int		ft_solution(int **g_matrix_sol, t_pos_map save)
{
	int i;
	int j;
	int cpt;
	
	cpt = 0;
	i = save.x;
	j = save.y;
	while (g_matrix_sol[i][j] != g_matrix_sol[i - 1][j] || i - 1 >= 0)
	{
		i--;
		cpt++;		
	}
	return (cpt);
}

int		bigest_square(t_pos_map save, t_map_chars pos)
{
	int cpt;
	int i;
	int j;

	i = save.x;
	y = save.y;
	cpt = ft_solution(g_matrix_sol, save);
	while (g_matrix_sol[i][j] 
}
