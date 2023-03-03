/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:29:05 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 11:10:37 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	free_malloc(char *buff)
{
	if (buff)
		free(buff);
	return (0);
}

int	free_char_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	free_int_map(int **str, int size)
{
	int	i;

	i = 0;
	while (i < size + 1)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
