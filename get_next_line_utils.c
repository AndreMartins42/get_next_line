/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:03:26 by marvin            #+#    #+#             */
/*   Updated: 2024/11/24 14:43:16 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*cpy;
	int		len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * len_s + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len_s + 1);
	return (cpy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	len_s;
	int	len_d;
	int	i;
	int	j;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
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

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;
	int	len_src;

	len_src = ft_strlen(src);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;

	if (!s1)
		s1 = calloc(1, 1);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (new == NULL)
		return (free(NULL), s1);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, (len_s1 + len_s2) + 1);
	return (free(s1), new);
}
