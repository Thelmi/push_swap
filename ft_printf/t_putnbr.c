/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:56:49 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/13 13:59:20 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_putnbr(int n)
{
	int	count;
	int	x;

	count = 0;
	if (n == -2147483648)
		return (t_putstr("-2147483648"));
	if (n < 0)
	{
		x = t_putchar('-');
		if (x == -1)
			return (x);
		count += x;
		n *= -1;
	}
	x = t_putpnbr(n);
	if (x == -1)
		return (-1);
	return (count + x);
}
