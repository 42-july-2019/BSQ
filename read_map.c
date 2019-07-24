/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:12:19 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/24 11:54:15 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"

int				last_three_chars(char *str)
{
	int i;

	i = 0;
	while (str[i + 2]
			&& str[i] != ' ' && str[i + 1] != ' ' && str[i + 2] != ' ')
		i++;
	return (i - 1);
}

int				allocate_memory(char *str_read, int size_end)
{
	int			i;
	int			nb_read;
	char		*size_read;

	if (!(size_read = (char *)malloc(sizeof(char) * size_end)))
		return (0);
	size_read[size_end] = '\0';
	i = -1;
	while (++i < size_end)
		size_read[i] = str_read[i];
	nb_read = ft_atoi(size_read);
	free(size_read);
	if (!nb_read)
		return (0);
	if (!(g_map_rep =
				((char **)malloc(sizeof(char *) * nb_read + 1))))
		return (0);
	if (!(g_matrix_sol =
				((int **)malloc(sizeof(int *) * nb_read + 1))))
		return (0);
	g_map_rep[nb_read + 1] = 0;
	g_matrix_sol[nb_read + 1] = 0;
	return (nb_read);
}

int				get_map_data(char *map_name, int size)
{
	int			i;
	int			map_ref;
	char		*str_read;
	char		curr_char[1];

	map_ref = open(map_name, O_RDONLY);
	if (map_ref == -1)
		return (0);
	i = -1;
	while (i <= size)
	{
		str_read = "";
		while (read(map_ref, curr_char, 1) &&
				(*curr_char != '\n'))
			str_read = ft_strdup_s(str_read, *curr_char);
		if (i == -1)
			free(str_read);
		else
			g_map_rep[i] = str_read;
		i++;
	}
	return (1);
}

t_map_chars		open_map_data(char *map_name, int *map_ref)
{
	int			size_end;
	int			nb_read;
	char		*str_read;
	char		curr_char[1];
	t_map_chars	result;

	result.empty = '\0';
	*map_ref = open(map_name, O_RDONLY);
	if (*map_ref == -1)
		return (result);
	str_read = "";
	while (read(*map_ref, curr_char, 1) && *curr_char != '\n')
		str_read = ft_strdup_s(str_read, *curr_char);
	size_end = last_three_chars(str_read);
	nb_read = allocate_memory(str_read, size_end);
	if (!nb_read)
		return (result);
	if (!get_map_data(map_name, nb_read))
		return (result);
	result.empty = str_read[size_end];
	result.obstacle = str_read[size_end + 1];
	result.full = str_read[size_end + 2];
	free(str_read);
	return (result);
}

t_map_chars		read_map(char *map_name)
{
	int			map_ref;
	t_map_chars result;
	// int			i;
	// int			j;

	result = open_map_data(map_name, &map_ref);
	if (close(map_ref) == -1)
		result.empty = '\0';
	return (result);
}
