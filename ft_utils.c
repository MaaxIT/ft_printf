/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:40:58 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/11/17 15:41:00 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Get the amount of digits in a number */
size_t	ft_count_digits(long long int nb)
{
	size_t	digits;

	if (nb < 0)
		nb = -nb;
	digits = 0;
	while (nb)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}
