/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:29:21 by fmarckma          #+#    #+#             */
/*   Updated: 2019/07/24 18:21:50 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int				**g_matrix_sol;
char			**g_map_rep;

typedef struct	s_map_chars
{
	char	empty;
	char	obstacle;
	char	full;
}				t_map_chars;

typedef struct	s_pos_map
{
	int x;
	int y;
	int value;
}				t_pos_map;

typedef struct	s_map_params
{
	int			size;
	t_map_chars	chars;

}				t_map_params;

int				ft_atoi(const char *str);
char			*ft_strdup_s(char *src, char c);
int				last_three_chars(char *str);
int				allocate_memory(char *str_read, int size_end);
void			read_stdin(void);
t_map_chars		read_map(char *map_name);
int				search_solution(char *map_name, t_map_params params);
int				ft_fill(char **g_map_rep, int **g_matrix_sol, t_map_chars pos);

#endif
