/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:54:27 by brouane           #+#    #+#             */
/*   Updated: 2025/10/31 15:25:37 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*strnum;
	int		size;
	long	nb;

	nb = n;
	size = ft_numlen(nb);
	strnum = malloc(sizeof(char) * (size + 1));
	if (!strnum)
		return (NULL);
	strnum[size] = '\0';
	if (nb == 0)
		strnum[0] = '0';
	if (nb < 0)
	{
		strnum[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		strnum[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (strnum);
}
