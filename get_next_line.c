#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

int main()
{
	int		fd;
	char	*result;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while((result = get_next_line(fd)) != NULL)
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
	char    *line;
	int     i;

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
	char    *next;
	int     i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	next = ft_strdup(buffer + i + 1);
	free(buffer);
	return (next);
}
char    *read_file(int  fd, char *cache)
{
	// preciso pegar todo o TXT e alocar em uma vari'avel, para ai sim verificar as linhas e trabalhar em cima dos \n"
	ssize_t bytes_lidos;
	char    *buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_lidos] = '\0';
		temp = ft_strjoin(cache, buffer);
		free(cache);
		cache = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (cache);
}