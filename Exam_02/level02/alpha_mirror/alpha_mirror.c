/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:37:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/14 13:08:36 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char *str = argv[1];

		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = 'z' - (str[i] - 'a');
			if (str[i] >= 'A' && str[i] <= 'Z')
                                str[i] = 'Z' - (str[i] - 'A');
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
