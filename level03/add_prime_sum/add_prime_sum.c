/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:26:02 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/07 11:21:12 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	ft_atoi(char *str)
{
	int res = 0;
	int i = 0;
	int sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '1' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	is_prime(int nb)
{
	int i = 2;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc,  char **argv)
{
	if (argc == 2)
	{
		int nb = ft_atoi(argv[1]);
		int sum = 0;
		int i = 2;

		if (nb < 1)
		{
			ft_putnbr(0);
			write(1, "\n", 1);
			return (0);
		}
		while (i <= nb)
		{
			if (is_prime(i))
				sum = sum + i;
			i++;
		}
		ft_putnbr(sum);
		write(1, "\n", 1);

	}
	else
	{
		ft_putnbr(0);
		write(1, "\n", 1);
	}
	return (0);
}
