/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:17:46 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 11:18:40 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_sort(int *tab, int length, int(*f)(int, int));
int ft_strcmp(int i, int j)
{
	return (i - j);
}

#include <stdio.h>
int main()
{
//	int str[] = {-406853, -370356, -358316, -298714, -206015, -194846, -128463, -87291, -85448, 34719, 46808};
//	int str[] = {100173, 103800, 123739, 175214, 196411, 230936, 236495, 241323, 252440, 307934, 333004, 345140, 355965, 388476, 398686};
	int str[] = {3, 4, 4, 5, 1, 0};
	printf("%d\n", ft_is_sort(str, 15, &ft_strcmp));
	return (0);
}