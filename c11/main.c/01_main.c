/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:46:09 by eushin            #+#    #+#             */
/*   Updated: 2023/02/27 18:56:38 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_map(int *tab, int length, int(*f)(int));
#include <stdio.h>

int plus_one(int nb)
{
	return (nb + 1);
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *tab;
	tab = ft_map(arr, 10, &plus_one);
	for(int i = 0; i < 10; i++)
		printf("%d ", tab[i]);
	return(0);
}
