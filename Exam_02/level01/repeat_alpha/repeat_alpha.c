/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:49:42 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:38 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	repeat_count(char c)
{
	char *cap_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *min_str = "abcdefghijklmnopqrstuvwxyz";

	if (c >= 'A' && c <= 'Z')
	{
		while (cap_str[i])
		{
			if (c == cap_str[i])
				return (i + 1);
			i++;
		}
	}
	else
}
