/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:45:52 by anmendes          #+#    #+#             */
/*   Updated: 2024/11/24 08:36:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif


int main(void)
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
}

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
		return (free(buffer), NULL);
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

char	*read_file(int fd, char *cache)
{
	ssize_t	bytes_lidos;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_lidos = read(fd, buffer, BUFFER_SIZE);
	while (bytes_lidos > 0)
	{
		buffer[bytes_lidos] = '\0';
		temp = ft_strjoin(cache, buffer);
		if (temp == NULL)
			return (free(cache), free(buffer), NULL);
		free(cache);
		cache = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_lidos = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (cache);
}
char	*ft_strchr(const char *s, int c)
{
	char	temp;

	if (s == NULL)
		return (NULL);
	temp = (char)c;
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (temp == '\0')
		return ((char *)s);
	return (NULL);
}
