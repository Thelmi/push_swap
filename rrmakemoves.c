/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrmakemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:27:36 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/06/17 22:41:57 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	rotatea_reverseb(int move_counta, int move_rcountb,
	t_Node **stacka, t_Node **stackb)
{
	while ((*stacka)-> positiona > 1 && move_counta > 0)
	{
		rotate(stacka);
		ft_printf("ra\n");
		move_counta--;
	}
	while (move_rcountb > 0)
	{
		reverse_rotate(stackb);
		ft_printf("rrb\n");
		move_rcountb--;
	}
}

void	rotateb_reversea(int move_rcounta, int move_countb,
	t_Node **stacka, t_Node **stackb)
{
	while ((*stacka)-> positiona > 1 && move_rcounta > 0)
	{
		reverse_rotate(stacka);
		ft_printf("rra\n");
		move_rcounta--;
	}
	while (move_countb > 0 && !((*stacka)->target > (*stackb)->first
			&& (*stacka)->data < (*stackb)->last))
	{
		rotate(stackb);
		ft_printf("rb\n");
		move_countb--;
	}
}

void	reverse_rotate_both_1(int move_rcountb, int move_rcount,
	t_Node **stacka, t_Node **stackb)
{
	while (move_rcountb > 0)
	{
		double_reverse_rotate(stacka, stackb);
		ft_printf("rrr\n");
		move_rcountb--;
	}
	while (move_rcount > 0)
	{
		reverse_rotate(stacka);
		ft_printf("rra\n");
		move_rcount--;
	}
}

void	reverse_rotate_both_2(int move_rcounta, int move_rcount,
	t_Node **stacka, t_Node **stackb)
{
	while (move_rcounta > 0)
	{
		double_reverse_rotate(stacka, stackb);
		ft_printf("rrr\n");
		move_rcounta--;
	}
	while (move_rcount > 0)
	{
		reverse_rotate(stackb);
		ft_printf("rrb\n");
		move_rcount--;
	}
}

void	reverse_rotate_both_0(t_moves moves, t_Node **stacka, t_Node **stackb)
{
	if ((*stacka)-> positiona > 1 && ((*stacka)->stacka_size + 1)
		- (*stacka)-> positiona >= (*stackb)->stackb_size
		- (*stackb)-> positionb)
		reverse_rotate_both_1(moves.move_rcountb,
			moves.move_rcount, stacka, stackb);
	else
		reverse_rotate_both_2(moves.move_rcounta,
			moves.move_rcount, stacka, stackb);
}
