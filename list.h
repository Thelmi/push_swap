/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:55 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/19 17:30:49 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct list
{
	int			positiona;
	int			positionb;
	int			bmax;
	int			bmin;
	int			first;
	int			last;
	int			data;
	int			stacka_size;
	int			stackb_size;
	int			cheapest_cost;
	int			target;
	struct list	*next;
}	t_Node;

typedef struct moves
{
	int	move_counta;
	int	move_countb;
	int	move_count;
	int	move_rcounta;
	int	move_rcountb;
	int	move_rcount;
}	t_moves;

t_Node	*is_valid(int ac, char **av);
t_Node	*create_node(int value);
t_Node	*lastnode(t_Node *list);
t_Node	*add_front(t_Node **node, int value);
t_Node	*add_back(t_Node *list, int val);
void	swap(t_Node *list);
void	double_swap(t_Node *listA, t_Node *listB);
void	push(t_Node **listA, t_Node **listB);
void	rotate(t_Node **list);
void	double_rotate(t_Node **listA, t_Node **listB);
void	reverse_rotate(t_Node **list);
void	double_reverse_rotate(t_Node **listA, t_Node **listB);
int		t_atoi(const char *str);
int		t_strchr(const char *s, int c);
int		is_integer(char *str);
int		isnot_term(char *str);
int		t_defence(char *str);
void	freelist(t_Node *list);
void	isdouble(t_Node *list);
void	largestnsmallest(t_Node *list);
void	firstnlast(t_Node *stack);
void	cheapest_one(t_Node *stack, int cost);
void	target_value(t_Node *stack, int target);
void	listsize(t_Node *stacka, t_Node *stackb);
void	positionab(t_Node *stacka, t_Node *stackb,
			int positiona, int positionb);
void	target(t_Node *stackA, t_Node *stackB);
void	makemoves(t_Node **stackA, t_Node **stackB);
void	rotate_pushback(t_Node **stacka, t_Node **stackb);
void	sort_three(t_Node **stackA);
void	mixer(t_Node **stacka, t_Node **stackb);
void	smallest_position(t_Node *stacka);
void	sort_five(t_Node **stacka, t_Node **stackb);
int		isascending(t_Node *list);
void	rotatea_reverseb(int move_counta, int move_rcountb,
			t_Node **stacka, t_Node **stackb);
void	rotateb_reversea(int move_rcounta, int move_countb,
			t_Node **stacka, t_Node **stackb);
void	reverse_rotate_both_1(int move_rcountb, int move_rcount,
			t_Node **stacka, t_Node **stackb);
void	reverse_rotate_both_2(int move_rcounta, int move_rcount,
			t_Node **stacka, t_Node **stackb);
void	reverse_rotate_both_0(t_moves moves, t_Node **stacka, t_Node **stackb);	
#endif