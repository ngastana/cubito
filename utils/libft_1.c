/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:06 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/20 15:31:53 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]) && (0 < n))
	{
		i++;
		n--;
	}
	if (n > 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] && s1[i] == ' ')
		i++;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] == s2[j])
			j++;
		if (j != (int)ft_strlen(s2))
			return (0);
		if (s2[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
