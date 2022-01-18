/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:35:02 by mriant            #+#    #+#             */
/*   Updated: 2022/01/11 18:02:48 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void     ft_printnbr(long long int n, int *result, char *base, int len)
{
        char    c;

        if (n / len != 0)
                ft_printnbr(n / len, result, base, len);
        c = base[(n % len)];
        *result += ft_putchar_int(c);
}

int ft_putdec(int n)
{
    int         result;
    long int    nb;

    result = 0;
    nb = n;
    if (nb < 0)
    {
        nb = -nb;
        result += ft_putchar_int('-');
    }
    ft_printnbr(nb, &result, "0123456789", 10);
    return (result);
}

int ft_putpoint(intptr_t n)
{
    int         result;

    result = 0;
    result += ft_putstr_int("0x");
    ft_printnbr(n, &result, "0123456789abcdef", 16);
    return (result);
}

int ft_putuint(unsigned int n)
{
    int         result;

    result = 0;
    ft_printnbr(n, &result, "0123456789", 10);
    return (result);
}