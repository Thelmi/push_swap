/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_putads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:33:20 by thelmy            #+#    #+#             */
/*   Updated: 2023/12/16 17:30:53 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_putads(void *ads)
{
	int					count;
	int					x;
	unsigned long		address;

	count = 0;
	address = (unsigned long)ads;
	x = t_putstr("0x");
	if (x == -1)
		return (-1);
	count += x;
	x = t_puthex(address, 0);
	if (x == -1)
		return (-1);
	return (count + x);
}
