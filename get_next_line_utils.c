
#include "get_next_line.h"

char	*ft_strdup(char *s) {
	char	*cpy;
	int		len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	cpy = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, (char *)s, len_s + 1);
	return (cpy);
}

int	ft_strlen(char *str) {
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size) {
	int	len_s = ft_strlen(src);
	int	len_d = ft_strlen(dst);
	int	i = len_d;
	int	j = 0;

	if (size <= len_d)
		return (len_s + size);
	while (src[j] && i < size - 1) {
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (len_s + len_d);
}

int	ft_strlcpy(char *dst, char *src, int size) {
	int	i;
	int	len_src;

	len_src = ft_strlen((char *)src);
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (len_src);
	for (i = 0; i < size - 1 && src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return (len_src);
}

char *ft_strjoin(char *s1, char *s2) 
{
    char *new;
    int len_s1;
    int len_s2;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2)); 
    if (!s2)
        return (ft_strdup(s1));
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!new) {
        free(s1);
        return (NULL);
    }
    ft_strlcpy(new, s1, len_s1 + 1);
    ft_strlcat(new, s2, len_s1 + len_s2 + 1);
    return (new);
}

