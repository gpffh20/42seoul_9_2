/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:42:32 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 09:38:02 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	print_error(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		input_map_solve();
	else
	{
		while (i < ac)
		{
			given_map_solve(av[i]);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
