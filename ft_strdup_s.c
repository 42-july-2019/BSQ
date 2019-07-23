/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:37:54 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/23 14:18:13 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_s(char *src, char c)
{
	int		i;
	int		length;
	char	*result;

	length = 0;
	while (src[length])
		length++;
	result = (char *)malloc(sizeof(char) * length + 2);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}
