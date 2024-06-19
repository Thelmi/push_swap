/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:11 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/11 15:42:33 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	t_putads(void *ads);
int	t_putchar(char c);
int	t_server(char specifier, va_list args);
int	t_putnbr(int n);
int	t_putpnbr(unsigned int n);
int	ft_printf(const char *format, ...);
int	t_putstr(char *str);
int	t_puthex(unsigned long n, int cap);

#endif