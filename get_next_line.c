#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t  ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char    *read_file(int  fd);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);


/*int main()
{
	int		fd;
	char	*result;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
}*/

 char *get_next_line(int fd)
{
	static char *buffer;
	char    *line;
	char    *temp;
	int     i;

	i = 0;
	if (fd < 0)
		return (NULL);
	buffer = read_file(fd);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	temp = ft_strdup(buffer + i + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
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
	}
	free(buffer);
	return (cache);
}
