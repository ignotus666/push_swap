/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:46:15 by dhanlon           #+#    #+#             */
/*   Updated: 2026/09/28 14:46:16 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *) malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, s1_len);
	ft_memcpy(dest + s1_len, s2, s2_len);
	dest[s1_len + s2_len] = '\0';
	return (dest);
}

static char	*read_and_join(int fd, char *buffer)
{
	char	*new_data;
	char	*joined;
	ssize_t	bytes_read;

	new_data = malloc(BUFFER_SIZE + 1);
	if (!new_data)
		return (NULL);
	bytes_read = read(fd, new_data, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(new_data);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		return (buffer);
	}
	new_data[bytes_read] = '\0';
	if (!buffer)
		return (new_data);
	joined = ft_strjoin(buffer, new_data);
	free(buffer);
	free(new_data);
	return (joined);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*nl_pos;
	char	*leftover_str;

	nl_pos = ft_strchr(*buffer, '\n');
	if (nl_pos)
	{
		line = ft_substr(*buffer, 0, nl_pos - *buffer + 1);
		leftover_str = ft_strdup(nl_pos + 1);
		free(*buffer);
		if (*leftover_str)
			*buffer = leftover_str;
		else
		{
			free(leftover_str);
			*buffer = NULL;
		}
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*updated_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		updated_buff = read_and_join(fd, buffer);
		if (updated_buff == buffer)
			break ;
		buffer = updated_buff;
		if (!buffer)
			break ;
	}
	if (!buffer)
		return (NULL);
	return (extract_line(&buffer));
}
