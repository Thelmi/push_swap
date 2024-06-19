/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:59:17 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:53:44 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	rotate_both_1(int move_countb, int move_count,
	t_Node **stacka, t_Node **stackb)
{
	while (move_countb > 0)
	{
		if ((*stackb)-> positionb == 1
			&& (*stacka)->target > (*stackb)->first
			&& (*stackb)->target < (*stackb)->last)
		{
			move_count++;
			break ;
		}
		double_rotate(stacka, stackb);
		ft_printf("rr\n");
		move_countb--;
	}
	while (move_count > 0)
	{
		if ((*stacka)->target == (*stacka)->data)
			break ;
		rotate(stacka);
		ft_printf("ra\n");
		move_count--;
	}
}

void	rotate_both_2(int move_counta, int move_count,
	t_Node **stacka, t_Node **stackb)
{
	while (((*stacka)-> positiona) > 1 && move_counta > 0)
	{
		double_rotate(stacka, stackb);
		ft_printf("rr\n");
		move_counta--;
	}
	while (move_count > 0 && (((*stackb)-> positionb == 1
				&& (*stackb)->stackb_size == 2
				&& !((*stacka)->data > (*stackb)->first
					&& (*stacka)->data < (*stackb)->last))
			|| ((((*stackb)-> positionb != 2)
					&& ((*stackb)->stackb_size != 2))
				|| !((*stacka)-> positiona == 1
					&& (*stackb)-> positionb == 1
					&& (*stacka)->data > (*stackb)->first
					&& (*stacka)->data < (*stackb)->last))))
	{
		rotate(stackb);
		ft_printf("rb\n");
		move_count--;
	}
}

void	rotate_both_0(t_moves moves, t_Node **stacka, t_Node **stackb)
{
	if (((*stacka)-> positiona) > 1 && ((*stacka)-> positiona - 1)
		>= (*stackb)-> positionb && ((*stacka)-> positiona != 2
			|| (*stackb)-> positionb != 2))
		rotate_both_1(moves.move_countb, moves.move_count, stacka, stackb);
	else
		rotate_both_2(moves.move_counta, moves.move_count, stacka, stackb);
}

void	moves_calculations(t_moves	*moves, t_Node **stacka, t_Node **stackb)
{
	moves->move_counta = (*stacka)-> positiona - 1;
	moves->move_countb = (*stackb)-> positionb;
	moves->move_count = 0;
	if (moves->move_counta > moves->move_countb)
		moves->move_count = moves->move_counta - moves->move_countb;
	else
		moves->move_count = moves->move_countb - moves->move_counta;
	moves->move_rcounta = (*stacka)-> stacka_size + 1 - (*stacka)-> positiona;
	moves->move_rcountb = (*stackb)-> stackb_size - (*stackb)-> positionb;
	moves->move_rcount = 0;
	if (moves->move_rcounta > moves->move_rcountb)
		moves->move_rcount = moves->move_rcounta - moves->move_rcountb;
	else
		moves->move_rcount = moves->move_rcountb - moves->move_rcounta;
}

void	makemoves(t_Node **stacka, t_Node **stackb)
{
	t_moves	moves;

	moves_calculations(&moves, stacka, stackb);
	if ((*stackb)->cheapest_cost != 1)
	{
		if ((*stacka)-> positiona <= ((*stacka)->stacka_size + 1) / 2
			&& (*stackb)-> positionb <= (*stackb)-> stackb_size / 2)
			rotate_both_0(moves, stacka, stackb);
		else if ((*stackb)-> positionb > (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona <= ((*stacka)->stacka_size + 1) / 2)
			rotatea_reverseb(moves.move_counta,
				moves.move_rcountb, stacka, stackb);
		else if ((*stackb)-> positionb <= (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona > ((*stacka)->stacka_size + 1) / 2)
			rotateb_reversea(moves.move_rcounta,
				moves.move_countb, stacka, stackb);
		else if ((*stackb)-> positionb > (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona > ((*stacka)->stacka_size + 1) / 2)
			reverse_rotate_both_0(moves, stacka, stackb);
	}
	push(stacka, stackb);
	ft_printf("pb\n");
}
