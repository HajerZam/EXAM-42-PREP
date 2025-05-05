/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:10:59 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/05 13:21:18 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *str = argv[1];

		while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		//printf("%d\n", i);
		while(str[i] && (str[i] != ' ' && (str[i] <= '\t' || str[i] >= '\r')))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
