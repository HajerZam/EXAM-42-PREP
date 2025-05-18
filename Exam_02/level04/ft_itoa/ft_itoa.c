/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:02:53 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/10 14:58:53 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_digits(int nb)
{
	int count = 0;

	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return(count);
}

char	*ft_itoa(int nbr)
{
	int len = count_digits(nbr);
	long nb = nbr;
	char *res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return NULL;
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] ='-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

