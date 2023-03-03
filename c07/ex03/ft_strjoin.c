/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:13:37 by eushin            #+#    #+#             */
/*   Updated: 2023/02/22 16:42:35 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_malloc(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		str_len;
	int		sep_len;
	char	*new_str;

	i = 0;
	str_len = 0;
	sep_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		str_len += j;
		i++;
	}
	while (sep[sep_len])
		sep_len++;
	str_len += sep_len * (size - 1);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*fill_string(int size, char **strs, char *sep, char *new_str)
{
	int	i;
	int	j;
	int	k;
	int	idx;

	i = -1;
	idx = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			new_str[idx++] = strs[i][j];
		k = -1;
		while (sep[++k] && i != size - 1)
			new_str[idx++] = sep[k];
	}
	new_str[idx] = 0;
	return (new_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;

	if (size == 0)
	{
		new_str = (char *)malloc(sizeof(char));
		if (!new_str)
			return (NULL);
	}
	else
		new_str = ft_malloc(size, strs, sep);
	new_str = fill_string(size, strs, sep, new_str);
	return (new_str);
}

/*
#include <stdio.h>
int main()
{
    char str1[] = "eushin";
    char str2[] = "gykoh";
    char str3[] = "sapark2";
    char str4[] = "dayou";
    char str5[] = "jusohn";
    char **strs = (char **) malloc(sizeof(char *) * 5);
    strs[0] = str1;
    strs[1] = str2;
    strs[2] = str3;
    strs[3] = str4;
    strs[4] = str5;
    char **strs_null = NULL;
    printf("%s\n", ft_strjoin(0, strs_null, "zz"));
}
*/