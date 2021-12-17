/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:40:58 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/12/17 19:31:49 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Get the amount of digits in an unsigned number with a specific base */
size_t	ft_count_udigits(unsigned long long nb, int base)
{
	size_t	digits;

	digits = 0;
	while (nb > 0)
	{
		digits++;
		nb /= base;
	}
	return (digits);
}

/* Get the amount of digits in a number */
size_t	ft_count_digits(long long int nb)
{
	size_t	digits;

	if (nb < 0)
		nb = -nb;
	digits = ft_count_udigits((unsigned long long)nb, 10);
	return (digits);
}

/* Erase the data in memory and replace it by \0 */
void	ft_bzero(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
