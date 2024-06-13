/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:55 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/10 12:51:05 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef list_H
# define list_H

// # include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct list
{
    int positionA;
    int positionB;
    int bmax;
    int bmin;
    int first;
    int last;
    int data;
    int stackA_size;
    int stackB_size;
    int cheapest_cost;
    int target;
    struct list *next;
}              Node;

Node    *is_valid(int ac, char **av);
Node    *createNode(int value);
Node    *lastnode(Node *list);
Node    *add_front(Node** node,int value);
Node    *add_back(Node *list, int val);
void    printlist(Node *list);
void    swap(Node *list);
void    double_swap(Node *listA, Node *listB);
void    push(Node **listA, Node **listB);
void    rotate(Node **list);
void    double_rotate(Node **listA, Node **listB);
void    reverse_rotate(Node **list);
void    double_reverse_rotate(Node **listA, Node **listB);
 
#endif