/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:06 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/04 20:36:51 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)	
		*dest++ = *src++;
	*dest = '\0';
}

char	*ft_strdup(const char *src)
{
	if (!src)
		return (NULL);
	size_t	len = ft_strlen(src) + 1;
	char	*dest = malloc(len);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len = ft_strlen(s1);
	size_t	s2_len = ft_strlen(s2);
	char	*join = malloc((s1_len + s2_len + 1));

	if (!s1 || !s2 || !join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}