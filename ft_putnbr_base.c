/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:40:49 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/12/15 09:02:38 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Check if the base is valid and can be used */
static int	ft_check_valid(const char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

/* Recursively used to print a number in a specific base */
static void	ft_print(int nb, const char *base, size_t len)
{
	size_t	nbr;
	size_t	is_negative;

	is_negative = 0;
	if (nb < 0)
	{
		nb *= -1;
		is_negative = 1;
	}
	nbr = nb;
	if (is_negative == 1)
		nbr = 4294967296 - nbr;
	if (nbr >= len)
		ft_print(nbr / len, base, len);
	ft_putchar(base[nbr % len]);
}

/* Print a number in a specific base */
size_t	ft_putnbr_base(int nb, char *base)
{
	size_t	len;

	len = ft_check_valid(base);
	if (!len)
		return (0);
	ft_print(nb, base, len);
	return (ft_count_digits((long long int)nb));
}
