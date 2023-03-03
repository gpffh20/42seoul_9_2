/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:32:48 by eushin            #+#    #+#             */
/*   Updated: 2023/02/22 13:18:22 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	while (str[i])
	{
		while (str[i] && is_sep(charset, str[i]))
			i++;
		if (str[i] && !(is_sep(charset, str[i++])))
			word_cnt++;
		while (str[i] && !(is_sep(charset, str[i])))
			i++;
	}
	return (word_cnt);
}

char	**ft_malloc(char **board, char *str, char *charset, int word_cnt)
{
	int	i;
	int	len;
	int	idx;

	idx = 0;
	i = 0;
	while (i < word_cnt)
	{
		len = 0;
		while (str[idx] && is_sep(charset, str[idx]))
			idx++;
		while (str[idx + len] && !is_sep(charset, str[idx + len]))
			len++;
		board[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!board[i])
			return (0);
		board[i][len] = 0;
		idx += len;
		i++;
	}
	return (board);
}

char	**fill_string(char **board, char *str, char *charset, int word_cnt)
{
	int	i;
	int	j;
	int	idx;

	idx = 0;
	i = 0;
	while (i < word_cnt)
	{
		j = 0;
		while (str[idx] && is_sep(charset, str[idx]))
			idx++;
		while (str[idx] && !is_sep(charset, str[idx]))
		{
			board[i][j] = str[idx];
			idx++;
			j++;
		}
		i++;
	}
	return (board);
}

char	**ft_split(char *str, char *charset)
{
	char	**board;
	int		i;
	int		word_cnt;

	i = 0;
	word_cnt = count_word(str, charset);
	board = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!board)
		return (0);
	board[word_cnt] = 0;
	board = ft_malloc(board, str, charset, word_cnt);
	board = fill_string(board, str, charset, word_cnt);
	return (board);
}
