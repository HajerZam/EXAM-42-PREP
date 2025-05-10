/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:19:02 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/06 14:54:18 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		int i = 0;
		char *str = argv[1];

		while(str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		int start = i;
		while (str[i] && !(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		int end = i;
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
                        i++;
		int word_started = 0;
		while (str[i])
		{
			while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			{
				i++;
				if (word_started)
					write(1, " ", 1);
				word_started = 0;
			}
			if (str[i])
			{
				write(1, &str[i], 1);
				word_started = 1;
				i++;
			}
		}
		if (word_started)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &str[start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

