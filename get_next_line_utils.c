/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:02:06 by alen              #+#    #+#             */
/*   Updated: 2025/02/07 20:08:35 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*c;

	c = s;
	while (*s)
		++s;
	return (s - c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*ret_s;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ret_s = (char *)s;
	while (ret_s[i])
	{
		if (ret_s[i] == (char)c)
			return (&ret_s[i]);
		++i;
	}
	if (ret_s[i] == (char)c)
		return (&ret_s[i]);
	return (NULL);
}
