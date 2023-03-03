/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:23:07 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 08:56:19 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int main()
{
	// char str[] = "animal";
	// char str1[] = "banana";
	// char str2[] = "holy";
	// char str3[] = "moly";
	// char str4[] = "gucamole";
	 char **tab;
	 tab = malloc(sizeof(char *) * 16);
	// tab[0] = str;
	// tab[1] = str1;
	// tab[2] = str2;
	// tab[3] = str3;
	// tab[4] = str4;
	// tab[5] = 0;
	
	tab[0] = "OX";
	tab[1] = "7j";
	tab[2] = "zP";
	tab[3] = "48f";
	tab[4] = "9svg";
	tab[5] = "1inq";
	tab[6] = "9Au2QNwy";
	tab[7] = "yGroxL16";
	tab[8] = "FOLQobXp";
	tab[9] = "45qCAG1X";
	tab[10] = "D019TkOxL";
	tab[11] = "HRJDQTg0Fr";
	tab[12] = "eysfbH5hvD";
	tab[13] = "7mSp2I1z36";
	tab[14] = "v06RjVtUemA4";
	tab[15] = "uGovM6tDYaCm";
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	for(int i = 0; i < 16; i++)
		printf("%s\n", tab[i]);
}