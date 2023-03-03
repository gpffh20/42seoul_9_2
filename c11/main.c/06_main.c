/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:04:44 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 02:22:13 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void ft_sort_string_tab(char **tab);

int main()
{
	char str[] = "animal";
	char str1[] = "banana";
	char str2[] = "holy";
	char str3[] = "moly";
	char str4[] = "gucamole";
	char **tab;
	tab = malloc(sizeof(char *) * 6);
	tab[0] = str;
	tab[1] = str1;
	tab[2] = str2;
	tab[3] = str3;
	tab[4] = str4;
	tab[5] = 0;
	
	ft_sort_string_tab(tab);
	for(int i = 0; i < 5; i++)
		printf("%s\n", tab[i]);
}