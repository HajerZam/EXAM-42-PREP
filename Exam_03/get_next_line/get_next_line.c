/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:20:51 by halzamma          #+#    #+#             */
/*   Updated: 2025/05/18 12:14:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_strlen(const char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

static char *ft_strdup(const char *str)
{
	int len = ft_strlen(str);
	int i = 0;
	char *dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char *ft_strjoin(char *str1, char *str2)
{
	if (!str1 && !str2)
		return (NULL);
	int len1 = ft_strlen(str1);
	int len2 = ft_strlen(str2);
	char	*result = malloc(len1 + len2 + 1);
	int i = 0;
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	int j = 0;
	while (str2[j])
	{
		result[i] = str2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

static char *free_and_null(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char *ft_substr(const char *str, int start, int len)
{
	if (!str)
		return (NULL);
	int s_len = ft_strlen(str);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	char *sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	int i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char *extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i = 0;

	if (!*stash || **stash == '\0')
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;

	// extract the line, including newline if present
	if ((*stash)[i] == '\n')
		line = ft_substr(*stash, 0, i + 1);
	else
		line = ft_substr(*stash, 0, i);
	if (!line)
		return (NULL);
	// preparing remaining part of stash
	if ((*stash)[i] == '\n')
		new_stash = ft_strdup(&(*stash)[i + 1]);
	else
		new_stash = NULL;

	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';

		// Join buffer to stash
		temp = ft_strjoin(stash, buffer);
		if (!temp)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		free(stash);
		stash = temp;
	}
	free(buffer);
	return (extract_line(&stash));
}


