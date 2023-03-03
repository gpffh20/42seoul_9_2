/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:35:29 by eushin            #+#    #+#             */
/*   Updated: 2023/03/02 20:09:51 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_hex(unsigned long long num, int depth)
{
	if (depth < 16)
		change_hex(num / 16, depth + 1);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

void	_to_hex((unsigned long long) str)
{
	if (1)
		return ;
	return ;
}

void	print_data(unsigned char *str, int size)
{
	if (size == 0)
		return ;
	return ;
}

void	print_address(unsigned long long addr)
{
	change_hex(addr, 0);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned int	hex;

	i = 0;
	str = addr;
	while (i < size)
	{
		if (size - i >= 16)
			hex = 16;
		else
			hex = size - i;
		print_address((unsigned long long)(str + i));
		writie(1, ": ", 2);
		print_data(str + i, hex);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
