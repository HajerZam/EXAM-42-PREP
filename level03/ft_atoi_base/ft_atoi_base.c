/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:36:47 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/07 11:50:52 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i])
	{
		res = res * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res + (str[i] - 'A' + 10);
		else
			break;
		i++;
	}
	return (res * sign);
}
