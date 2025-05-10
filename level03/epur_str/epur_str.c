/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:22:49 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/07 11:34:15 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;
		int len = ft_strlen(str) - 1;
		int word_flag = 0;

		while (str[len] == ' ' || (str[len] >= '\t' && str[len] <= '\r'))
			len--;
		while(i <= len)
		{
			if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			{
				if (word_flag == 1)
				{
					write(1, " ", 1);
					word_flag = 0;
				}
			}
			else
			{
				word_flag = 1;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
