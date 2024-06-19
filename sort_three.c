/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:29 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/19 18:42:55 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	sort_three_part2(t_Node **stackA)
{
	if ((*stackA)->data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data < (*stackA)-> next -> next -> data)
	{
		swap(*stackA);
		ft_printf("sa\n");
	}
	else
	{
		swap(*stackA);
		ft_printf("sa\n");
		rotate(stackA);
		ft_printf("ra\n");
	}
}

void	sort_three(t_Node **stackA)
{
	if ((*stackA)->data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data > (*stackA)-> next -> next -> data)
	{
		rotate(stackA);
		ft_printf("ra\n");
		swap(*stackA);
		ft_printf("sa\n");
	}
	else if ((*stackA)-> data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data < (*stackA)-> next -> next -> data
		&& (*stackA)-> data > (*stackA)-> next -> next -> data)
	{
		rotate(stackA);
		ft_printf("ra\n");
	}
	else if ((*stackA)->data < (*stackA)-> next -> data
		&& (*stackA)-> next -> data > (*stackA)-> next -> next -> data
		&& (*stackA)-> data > (*stackA)-> next -> next -> data)
	{
		reverse_rotate(stackA);
		ft_printf("rra\n");
	}
	else
		sort_three_part2(stackA);
}
