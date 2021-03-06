/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:51:07 by mriant            #+#    #+#             */
/*   Updated: 2022/01/19 13:52:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef long long unsigned int	t_llui;

int		ft_printf(const char *s, ...);
void	ft_printint(long long int n, int *result, char *base, int len);
void	ft_printuint(t_llui n, int *result, char *base, int len);
int		ft_putdec(int n);
int		ft_putpoint(intptr_t n);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);
int		ft_putuint(unsigned int n);
int		ft_putx(unsigned int n);
int		ft_putxmaj(unsigned int n);
size_t	ft_strlen(const char *s);

#endif