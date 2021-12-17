/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:57:39 by mpeharpr          #+#    #+#             */
/*   Updated: 2021/12/17 16:16:45 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

/* ft_printf.c */
int	ft_printf(const char *str, ...);

/* ft_types.c */
size_t	ft_putstr(const char *str);
size_t	ft_putchar(const char c);
size_t	ft_putnbr(const int nb);
size_t	ft_putnbr(int nb);
size_t	ft_putunbr(unsigned int nb);
size_t	ft_putptr(const void *ptr);

/* ft_utils.c */
size_t	ft_count_digits(long long int nb);

/* ft_putnbr_base.c */
size_t	ft_putnbr_base(int nb, char *base);

#endif
