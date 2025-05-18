/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:48:19 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/14 14:32:19 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		const char *ptr = s2;
		while (*ptr)
		{
			if (*s1 == *ptr)
				return (char *)ptr;
			ptr++;
		}
		s1++;
	}
	return (NULL);
}
