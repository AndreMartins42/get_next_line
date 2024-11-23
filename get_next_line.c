#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int main()
{
	int		fd;
	int 	bytes_lidos;
	char	*result;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while((result = get_next_line(fd)) != NULL)
	{
		printf("%s\n", result);
		//free(result);
	}
	close(fd);
	return (0);
}

 char *get_next_line(int fd)
{
	char	*buffer;
	char    *line;
	char    *temp;
	int     i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd);
	if (buffer == NULL || *buffer == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	temp = ft_strdup(buffer + i + 1);
	free(buffer);
	buffer = temp;
	return (line);
}

char    *read_file(int  fd) // ESTA FUNCAO E SOMENTE UM READ E RETORNA UMA STRING DO TXT TODO DE ACORDO COM O BUFFER
{
	// preciso pegar todo o TXT e alocar em uma vari'avel, para ai sim verificar as linhas e trabalhar em cima dos \n"
	ssize_t bytes_lidos;
	char    *buffer;
	char	*cache = NULL;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_lidos] = '\0';
		cache = ft_strjoin(cache, buffer);
		if (cache == NULL)
		{	free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (cache);
}
