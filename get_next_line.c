/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:39:57 by anmendes          #+#    #+#             */
/*   Updated: 2024/11/30 12:57:44 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

/* int main(void)
{
	int	fd;
	char *result;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((result = get_next_line(fd))!= NULL)
	{
		printf("%s", result);
		free(result);
	}
	close(fd);
	return (0);
} */

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

char	*ft_next(char *buffer)
{
	char	*next;
	int		i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	next = ft_strdup(buffer + i + 1);
	if (next == NULL)
		return (NULL);
	free(buffer);
	return (next);
}

char	*read_file(int fd, char *buffer)
{
	ssize_t	bytes_lidos;
	char	*cache;
	char	*temp;

	cache = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (cache == NULL)
		return (NULL);
	bytes_lidos = read(fd, cache, BUFFER_SIZE);
	while (bytes_lidos > 0)
	{
		cache[bytes_lidos] = '\0';
		temp = ft_strjoin(buffer, cache);
		if (temp == NULL)
			return (free(cache), free(buffer), NULL);
		free(buffer);
		buffer = temp;
		if (ft_strchr(cache, '\n'))
			break ;
		bytes_lidos = read(fd, cache, BUFFER_SIZE);
	}
	free(cache);
	if (bytes_lidos < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
