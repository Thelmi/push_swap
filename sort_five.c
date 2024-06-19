/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:13:04 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 19:23:00 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	reverse_rotate_five(t_Node **stacka, t_Node **stackb)
{
	int	positiona;

	positiona = (*stacka)-> stacka_size + 1 - (*stacka)-> positiona;
	while (positiona > 0)
	{
		reverse_rotate(stacka);
		ft_printf("rra\n");
		positiona--;
	}
	push(stacka, stackb);
	ft_printf("pb\n");
}

static void	rotate_five(t_Node **stacka, t_Node **stackb)
{
	int	positiona;

	positiona = (*stacka)-> positiona;
	while ((positiona - 1) > 0)
	{
		rotate(stacka);
		ft_printf("ra\n");
		positiona--;
	}
	push(stacka, stackb);
	ft_printf("pb\n");
}

void	sort_five(t_Node **stacka, t_Node **stackb)
{
	largestnsmallest(*stacka);
	smallest_position(*stacka);
	listsize(*stacka, *stackb);
	if ((*stacka)-> positiona <= ((*stacka)-> stacka_size + 1) / 2)
		rotate_five(stacka, stackb);
	else
		reverse_rotate_five(stacka, stackb);
}
