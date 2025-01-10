/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:17:41 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/08 16:17:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnl.h"

char	*ft_gnl_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_gnl_memset(void *ptr, int c, size_t n)
{
	while (n--)
		*((unsigned char *)(ptr + n)) = c;
	return (ptr);
}

void	*ft_gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (size && (total_bytes / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_gnl_memset(ptr, 0, total_bytes);
	return (ptr);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
