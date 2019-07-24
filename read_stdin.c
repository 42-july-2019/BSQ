/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:17:23 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/24 17:38:12 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

t_map_params	create_map(char *input_str)
{
	int				size_end;
	int				nb_read;
	t_map_params	result;

	size_end = last_three_chars(input_str);
	nb_read = allocate_memory(input_str, size_end);
	if (!nb_read)
	{
		write(2, "map error\n", 10);
		exit(EXIT_FAILURE);
	}
	result.size = nb_read;
	result.chars.empty = input_str[size_end];
	result.chars.obstacle = input_str[size_end + 1];
	result.chars.full = input_str[size_end + 2];
	free(input_str);
	return (result);
}

int				read_curr_line(int curr_line, char *input_str)
{
	int i;
	t_map_params	params;

	params.size = 0;
	if (curr_line == -1)
	{
		if (*input_str == '<' && *(input_str + 2))
		{
			i = (*(input_str + 1) == ' ' ? 2 : 1);
			return(((search_solution(input_str + i, params)) ?
						EXIT_SUCCESS : EXIT_FAILURE));
		}
		else
			params = create_map(input_str);
	}
	else
	{
		if (curr_line == params.size - 1)
		{
			g_map_rep[curr_line] = input_str;
			write(1, "\n", 1);
			return(((search_solution(input_str, params)) ?
						EXIT_SUCCESS : EXIT_FAILURE));
		}
		else
			g_map_rep[curr_line] = input_str;
	}
	return (-1);
}

void			read_stdin(void)
{
	// int				i;
	int				status;
	int				curr_line;
	char			read_input[1];
	char			*input_str;


	input_str = "";
	curr_line = -1;
	while (read(0, read_input, 1))
	{
		if (*read_input != '\n')
			input_str = ft_strdup_s(input_str, *read_input);
		if (*read_input == '\n')
		{
			status = read_curr_line(curr_line, input_str);
			if (status != -1)
				exit(status);
			// if (curr_line == -1)
			// {
			// 	if (*input_str == '<' && *(input_str + 2))
			// 	{
			// 		i = (*(input_str + 1) == ' ' ? 2 : 1);
			// 		exit((search_solution(input_str + i, params)) ?
			// 				EXIT_SUCCESS : EXIT_FAILURE);
			// 	}
			// 	else
			// 		params = create_map(input_str);
			// }
			// else
			// {
			// 	if (curr_line == params.size - 1)
			// 	{
			// 		g_map_rep[curr_line] = input_str;
			// 		write(1, "\n", 1);
			// 		exit((search_solution(input_str, params)) ?
			// 				EXIT_SUCCESS : EXIT_FAILURE);
			// 	}
			// 	else
			// 		g_map_rep[curr_line] = input_str;
			//}
			curr_line++;
			input_str = "";
		}
	}
}
