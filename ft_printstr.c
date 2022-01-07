/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:59:55 by mriant            #+#    #+#             */
/*   Updated: 2022/01/07 11:00:33 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putchar_int(char c)
{
    int result;

    result = write(1, &c, 1);
    return (result);
}

int ft_putstr_int(char *s)
{
    int result;

    result = write(1, s, ft_strlen(s));
    return (result);
}