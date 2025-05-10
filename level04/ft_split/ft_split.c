/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:08:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/10 15:43:03 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	count = 0;
	int	in_word = 0;
	int	i = 0;

	while (str[i])
	{
		if (!is_space(str[i]) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(str[i]))
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	*copy_word(char *str, int len)
{
	char *word = malloc(len + 1);
	int i = 0;

	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}

	word[len] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	int word_count = count_words(str);
	char **result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	int i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;

		char *start = str;
		int len = 0;
		while (*str && !is_space(*str))
		{
			len++;
			str++;
		}
		if (len > 0)
		{
			result[i] = copy_word(start, len);
			if (!result[i])
			{
				while (i > 0)
					free (result[--i]);
				free(result);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = (NULL);
	return (result);
}

