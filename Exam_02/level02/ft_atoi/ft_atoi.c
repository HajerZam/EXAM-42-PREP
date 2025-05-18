/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:17:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/14 13:28:12 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("lets seee\n");
	printf("\n");
	const char *str1 = "0";
	const char *str2 = "2344";
	const char *str3 = "-8659";
	printf("the og atoi :\nstr1 = %d\n str2 = %d\n str3 = %d\n", atoi(str1), atoi(str2), atoi(str3));
	printf("the MY atoi :\nstr1 = %d\n str2 = %d\n str3 = %d\n", ft_atoi(str1), ft_atoi(str2), ft_atoi(str3));
	return (0);
}
