/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:10:21 by eushin            #+#    #+#             */
/*   Updated: 2023/03/01 04:50:01 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int ft_any(char **tab, int(*f)(char*));

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int main()
{
	char str1[] = "eushin";
    char str2[] = "gykoh";
    char str3[] = "1232";
    char str4[] = "dayou";
    char str5[] = "jusohn";
    char **strs = (char **) malloc(sizeof(char *) * 5);
    strs[0] = str1;
    strs[1] = str2;
    strs[2] = str3;
    strs[3] = str4;
    strs[4] = str5;
	
	printf("%d", ft_any(strs, &ft_str_is_numeric));
	return (0);
}