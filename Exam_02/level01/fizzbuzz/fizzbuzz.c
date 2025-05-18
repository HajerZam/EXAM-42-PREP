/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:23:26 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/05 13:33:17 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int nb)
{
	if (nb >= 10)
		print_num(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	main(int argc, char **argv)
{
	int i = 1;

	while (i <= 100)
	{
		if( i == 3 || i == 5 || i % 5 == 0 || i % 3 == 0)
		{
			if (i == 3 || i % 3 == 0)
				write(1, "fizz", 4);
			if (i == 5 || i % 5 == 0)
				write(1, "buzz", 4);
		}
		else
			print_num(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
