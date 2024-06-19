/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:54 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/19 21:28:19 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	bye(t_Node **stack)
{
	write (2, "Error\n", 6);
	freelist(*stack);
	exit(1);
}

void	integer_assign(t_Node **stack, t_Node **tmp, char*str)
{
	t_Node	*nextnode;

	if (is_integer(str))
	{
		if (!*stack)
		{
			*stack = create_node(t_atoi(str));
			*tmp = *stack;
		}
		else
		{
			nextnode = create_node(t_atoi(str));
			(*tmp)-> next = nextnode;
			*tmp = nextnode;
		}
	}
	else
	{
		write (2, "Error\n", 6);
		if (*stack)
			freelist(*stack);
		exit(1);
	}
}

void	split_assign(t_Node **stack, char **splitted, t_Node **tmp)
{
	t_Node	*nextnode;
	int		i;

	nextnode = NULL;
	i = 0;
	if (!*stack)
	{
		*stack = create_node(t_atoi(splitted[0]));
		*tmp = *stack;
		i = 1;
	}
	while (splitted[i])
	{
		nextnode = create_node(t_atoi(splitted[i]));
		(*tmp)-> next = nextnode;
		(*tmp) = (*tmp)-> next;
		i++;
	}
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	split_cheaker(char *str, t_Node **stack, t_Node **tmp)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(str, ' ');
	while (splitted[i])
	{
		if (!is_integer(splitted[i]))
		{
			write (2, "Error\n", 6);
			i = 0;
			while (splitted[i])
			{
				free(splitted[i]);
				i++;
			}
			free(splitted);
			freelist((*stack));
			exit(1);
		}
		i++;
	}
	split_assign(stack, splitted, tmp);
}

t_Node	*is_valid(int ac, char **av)
{
	int		i;
	t_Node	*head;
	t_Node	*tmp;

	i = 1;
	head = NULL;
	tmp = NULL;
	if (ac <= 1)
		exit(1);
	while (i < ac)
	{
		if (t_defence(av[i]) && isnot_term(av[i]))
		{
			if (t_strchr(av[i], ' '))
				split_cheaker(av[i], &head, &tmp);
			else
				integer_assign(&head, &tmp, av[i]);
		}
		else
			bye(&head);
		i++;
	}
	isdouble(head);
	return (head);
}
