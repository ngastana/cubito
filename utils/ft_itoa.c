/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:44:37 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/17 18:34:24 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_count_me(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = ft_count_me(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (0);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	while (len != 0 && n > 0)
	{
		len--;
		num[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
