/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:39:40 by mriant            #+#    #+#             */
/*   Updated: 2022/01/11 18:02:45 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *s, ...)
{
    int i;
    int total;
    va_list ap;

    i = 0;
    total = 0;
    va_start(ap, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            if (s[i + 1] == 'c')
                total += ft_putchar_int(va_arg(ap, int));
            if (s[i + 1] == 's')
                total += ft_putstr_int(va_arg(ap, char *));
            if (s[i + 1] == 'd' || s[i + 1] == 'i')
                total += ft_putdec(va_arg(ap, int));
            if (s[i + 1] == 'p')
                total += ft_putpoint((intptr_t) va_arg(ap, void *));
            if (s[i + 1] == 'u')
                total += ft_putuint(va_arg(ap, unsigned int));    
            i += 2;
        }
        else
        {
            total += write (1, &s[i], 1);
            i ++;
        }
    }
    va_end(ap);
    return (total);
}