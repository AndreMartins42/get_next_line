/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:03:26 by marvin            #+#    #+#             */
/*   Updated: 2024/11/24 08:03:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len_s;
	
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	cpy = (char *)malloc(sizeof(char) * len_s + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len_s + 1);
	return (cpy);
}

size_t ft_strlen(char *str)
{
	size_t i = 0;

	if (str == NULL)
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
	size_t	len_src;

	len_src = ft_strlen((char *)src);
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
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
	{
		free((char *)s1);
		return (NULL);
	}
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, (len_s1 + len_s2) + 1);
	return (new);
}
