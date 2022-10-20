/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:43:50 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/25 18:27:30 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_free(char **split, int word)
{
	while (word > 0)
	{
		word--;
		free(split[word]);
	}
	free(split);
	return (-1);
}

static int ft_is_separator(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static void write_word(char *list, char *s, char c)
{
	int i;

	i = 0;
	while (ft_is_separator(s[i], c) == 0)
	{
		list[i] = s[i];
		i++;
	}
	list[i] = '\0';
}

static int write_split(char **list, char *s, char c)
{
	int i;
	int j;
	int word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_is_separator(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_separator(s[i + j], c) == 0)
				j++;
			list[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!list[word])
				return (ft_free(list, word));
			write_word(list[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (word);
}

char **ft_split(char const *s, char c)
{
	char **list;
	int words;
	int word;
	int i;

	word = 0;
	i = 0;
	words = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (ft_is_separator(s[i + 1], c) == 1 && ft_is_separator(s[i], c) == 0)
			words++;
		i++;
	}
	list = (char **)malloc((words + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list[words] = NULL;
	word = write_split(list, (char *)s, c);
	if (word == -1)
		return (0);
	return (list);
}
