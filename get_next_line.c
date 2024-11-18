#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t  ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char    *read_file(int  fd);
char	*get_next_line(int fd);


int main()
{
	int		fd;
	char	*result;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	result = read_file(fd);
	printf("%s\n", result);
	free(result);
}

/* char *get_next_line(int fd)
{
	char	*result;

	if (fd < 0)
		return (NULL);
	result = read_file(fd);
	return(result);
}  */

char    *read_file(int  fd) // ESTA FUNCAO E SOMENTE UM READ E RETORNA UMA STRING DO TXT TODO DE ACORDO COM O BUFFER
{
	// preciso pegar todo o TXT e alocar em uma vari'avel, para ai sim verificar as linhas e trabalhar em cima dos \n"
	ssize_t bytes_lidos;
	char    *buffer;
	char	*cache = NULL;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
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

size_t ft_strlen(char *str)
{
	size_t i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return i;
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;
	size_t	j;

	len_s = ft_strlen((char *)src);
	len_d = ft_strlen((char *)dst);
	if (size <= len_d)
		return (len_s + size);
	j = 0;
	i = len_d;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_s + len_d);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;
 	
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, (len_s1 + len_s2) + 1);
	free((char *)s1);
	return (new);
}
