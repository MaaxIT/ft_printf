/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:55:58 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/12/17 16:14:29 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print a string to console */
size_t	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

/* Print a character to console */
size_t	ft_putchar(const char c)
{
	if (!c)
		return (0);
	write(1, &c, 1);
	return (1);
}

/* Print an int to console */
size_t	ft_putnbr(int nb)
{
	long long int	final;

	final = nb;
	if (final < 0)
	{
		final *= -1;
		ft_putchar('-');
	}
	if (final > 9)
	{
		ft_putnbr((final / 10));
		ft_putchar((final % 10 + '0'));
	}
	else
		ft_putchar((final + '0'));
	return (ft_count_digits(final));
}

/* Print an unsigned int to console */
size_t	ft_putunbr(unsigned int nb)
{
	unsigned long long int	final;

	final = nb;
	if (final > 9)
	{
		ft_putnbr((final / 10));
		ft_putchar((final % 10 + '0'));
	}
	else
		ft_putchar((final + '0'));
	return (ft_count_digits(final));
}

/* Print the address of a pointer to the console */
size_t	ft_putptr(const void *ptr)
{
	unsigned long	ptr_long;
	const char		*base;
	char			final[10];
	size_t			index;

	ptr_long = (unsigned long)ptr;
	base = "0123456789abcdef";
	index = 9;
	final[index--] = '\0';
	while ((ptr_long / 16) > 0)
	{
		final[index--] = base[(ptr_long % 16)];
		ptr_long /= 16;
	}
	final[index] = base[(ptr_long % 16)];
	return (ft_putstr("0x") + ft_putstr(final));
}
