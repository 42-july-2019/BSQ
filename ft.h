/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:29:21 by fmarckma          #+#    #+#             */
/*   Updated: 2019/07/23 22:02:15 by fmarckma         ###   ########.fr       */
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

int				ft_atoi(const char *str);
char			*ft_strdup_s(char *src, char c);
t_map_chars		read_map(char *map_name);

#endif
