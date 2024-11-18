#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t  ft_strlen(char *str);
char    *ft_strjoin(char const *s1, char const *s2);

int main(void)
{
    int         fd;
    char        *linha;
    ssize_t     bytes_lidos;
    static char buffer[BUFFER_SIZE];

    fd = open("teste.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        int i = 0;
        while (i < bytes_lidos)
        {
            if (buffer[i] == '\n')
            {
                buffer[i] = '\0';
                //linha = ft_strjoin(linha, buffer);
                printf("Linha lida: %s\n", buffer);
                //free(linha);
                break;
            }
            i++;
        }
    }
    if (bytes_lidos < 0)
        printf("Erro ao ler o arquivo\n");

    close(fd);
    return 0;
}
size_t ft_strlen(char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}
// Função para juntar duas strings
/*char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len_s1 = s1 ? ft_strlen((char *)s1) : 0;
    size_t len_s2 = ft_strlen((char *)s2);
    char *new = malloc(len_s1 + len_s2 + 1);
    if (!new)
        return NULL;

    if (s1)
        for (size_t i = 0; i < len_s1; i++)
            new[i] = s1[i];
    for (size_t i = 0; i < len_s2; i++)
        new[len_s1 + i] = s2[i];

    new[len_s1 + len_s2] = '\0';
    return new;
}*/
