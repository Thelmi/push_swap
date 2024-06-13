

#include "list.h"
#include <stdio.h>
void printlist(Node* list)
{
	Node *tmp = list;
	while (tmp != NULL)
	{
		// printf("data: %d\n max: %d\n min: %d\n ", tmp -> data, tmp ->bmax, tmp -> bmin);
		// printf("data: %d\n first: %d\n last: %d\n",tmp ->data ,tmp ->first, tmp ->last);
		// printf("data: %d\n", tmp ->data);
		tmp = tmp -> next;
	}
}
void largestnsmallest(Node *list)
{
	Node *tmp = list;
	
	int min = INT_MAX;
	int max = INT_MIN;
	while (tmp != NULL)
	{
		if (max < tmp -> data)
			max = tmp -> data;
		if (min > tmp -> data)
			min = tmp -> data;
		tmp = tmp -> next;
	} 
	tmp = list;
	while (tmp != NULL)
	{
		tmp -> bmax = max;
		tmp -> bmin = min;
		tmp = tmp -> next;
	}
}

void firstnlast(Node *stack)
{
	Node *tmp = stack;
	int last = lastnode(stack) -> data;
	int first = stack -> data;
	while (tmp != NULL)
	{
		tmp ->first = first;
		tmp ->last = last;
		tmp = tmp -> next;
	}
}

void cheapest_one(Node *stack, int cost)
{
	Node *tmp = stack;

	while (tmp != NULL)
	{
		tmp ->cheapest_cost = cost;
		tmp = tmp -> next;
	}
}

void target_value(Node *stack, int target)
{
	Node *tmp = stack;

	while (tmp != NULL)
	{
		tmp ->target = target;
		tmp = tmp -> next;
	}
}

void listsize(Node *stacka , Node *stackb)
{
	Node *tmp = stacka;
	int count = 0;
	while (tmp != NULL) // no point 
	{
		count++;
		tmp = tmp -> next;
	}
	tmp = stacka;
	while (tmp != NULL)
	{
		tmp -> stackA_size = count;
		tmp = tmp ->next;
	}
	tmp = stackb;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp ->next;
	}
	tmp = stackb;
	while (tmp != NULL)
	{
		tmp -> stackB_size = count;
		tmp = tmp ->next;
	}
}

void positionab(Node *stacka, Node *stackb, int positiona, int positionb)
{
	Node *tmp = stacka;
	while (tmp != NULL)
	{
		tmp ->positionA = positiona;
		tmp ->positionB = positionb;
		tmp = tmp -> next;
	}
	tmp = NULL;
	tmp = stackb;
	while (tmp != NULL)
	{
		tmp ->positionA = positiona;
		tmp ->positionB = positionb;
		tmp = tmp -> next;
	}
}
void target(Node *stackA, Node *stackB)
{
	Node *tmpA = stackA;
	Node *tmpB = stackB;
	int  cheapest_cost = INT_MAX;
	// int  target = 0;
	int positionA = 0;
	int positionB = 1;
	int cost = 0;

	listsize((stackA), (stackB));
	largestnsmallest((stackB));
	firstnlast(stackB);

	while (tmpA != NULL)
	{
		positionA++;
		 
		tmpB = stackB;
		positionB = 1;
		while (tmpB != NULL)
		{
			if ((tmpB->next != NULL && (tmpA->data < tmpB->data && tmpA->data > tmpB->next->data))
			|| (tmpB->data == tmpB->bmin && (tmpA->data > tmpB->bmax || tmpA->data < tmpB->bmin))
			|| (tmpA->data > tmpB->first && tmpA->data < tmpB->last))
			{
				if (positionA <= (tmpA ->stackA_size + 1) / 2)
				{
					if (positionB <= tmpB ->stackB_size/ 2)
						{
							if (positionB == 1 && stackB ->stackB_size == 2 && !(tmpA->data > tmpB->first && tmpA->data < tmpB->last)) 
							{
								cost = 2; 
								// printf("Yaay\n");
								// cost = positionA + ((tmpB ->stackB_size + 1) - positionB);
								//printf("11)okayokay");
							}
							else if (positionB == 2 && stackB ->stackB_size == 2) 
							{
								cost = 1;
								// cost = positionA + ((tmpB ->stackB_size + 1) - positionB);
								//printf("11)okayokay");
							}
							else if (positionA == 1 && positionB == 1 && tmpA->data > tmpB->first && tmpA->data < tmpB->last) 
							{
								cost = 1;
							    //printf("0)cost: %d = positionA %d\n",cost, positionA);
							}
							else if (positionA > positionB)
							{
								cost = positionA;
								// printf("1) cost: %d = positionA %d\n",cost, positionA);
							}
							else
							{
								//cost = positionB + 1;
								cost = positionB + 1;
								//  printf("2) cost: %d = positionB: %d + 1\n",cost, positionB);
							}
						}
					else
						{
							// if (positionB == 1 && stackB ->stackB_size == 2) 
							// {
							// 	cost = 2; 
							// 	// cost = positionA + ((tmpB ->stackB_size + 1) - positionB);
							// 	//printf("11)okayokay");
							// }
							// else if (positionB == 2 && stackB ->stackB_size == 2)
							// {
							// 	cost = 1;
							// 	// cost = positionA + ((tmpB ->stackB_size + 1) - positionB);
							// 	//printf("11)okayokay");
							// }
							// else
							// {
							cost = positionA + (tmpB ->stackB_size - positionB); 
							// printf("3) cost: %d = postionA: %d +(tmpB ->stackB_size: %d - postionB: %d\n)",cost, positionA,tmpB ->stackB_size, positionB);
							// }
						} 
				}
				else
				{
					if (positionB <= tmpB->stackB_size / 2)
					{ 
						//if (stackB ->stackB_size == 2)
						//		positionB--;
						cost = (tmpA ->stackA_size + 2) - positionA + positionB;
						if (tmpA->data > tmpB->first && tmpA->data < tmpB->last)
							cost--;
						// printf("4) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d + positionB: %d\n", cost, tmpA -> stackA_size +2, positionA, positionB);
					}
					else
					{
						if ((tmpA ->stackA_size + 1) - positionA > tmpB ->stackB_size - positionB) 
						{
							cost = (tmpA -> stackA_size + 2) - positionA;
							//  printf("5) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d\n", cost, tmpA -> stackA_size + 2, positionA);
						} 
						else
						{
							cost = (tmpB ->stackB_size - positionB) + 1;
							//  printf("6) cost: %d = (tmpB -> stackA_size: %d - positionB +1: %d\n)", cost, tmpB -> stackB_size, positionB + 1);
						}
					}
				}                 
				if (cost < cheapest_cost)
				{
					cheapest_cost = cost;
					// printf("cheapest cost: %d\n",cheapest_cost);
					// target = tmpA -> data;
					// tmpA -> target = target;
					// tmpA -> target = tmpA -> data; 

					tmpA ->positionA = positionA;
					tmpB -> positionB = positionB;


					// printf("first: %d\n", tmpB ->first);
					// printf("last: %d\n", tmpB ->last);
					// printf("tmpA -> data: %d\n", tmpA -> data);
					// printf("bmax:%d\n",tmpB->bmax);
					// printf("bmin:%d\n",tmpB->bmin);
					// printf("possible cheapest cost: %d\n", cheapest_cost); 
					positionab(stackA, stackB, positionA, positionB);
					target_value(stackA, tmpA -> data);
					target_value(stackB, tmpA -> data);
				}
				break;
			}
			positionB++;
			tmpB = tmpB -> next;        
		}
		tmpA = tmpA -> next;
	}
	// printf("cheapest cost: %d\n",cheapest_cost);
	cheapest_one(stackA, cheapest_cost);
	cheapest_one(stackB, cheapest_cost);
	
}
void makemoves(Node **stackA, Node **stackB)
{
	
	int move_counta = (*stackA) -> positionA - 1;
	int move_countb = (*stackB) -> positionB; 

	int move_count;
	if (move_counta > move_countb)
		move_count = move_counta - move_countb;
	else
		move_count = move_countb - move_counta;

	int move_rcounta = (*stackA) -> stackA_size + 1 - (*stackA) -> positionA;
	int move_rcountb = (*stackB) -> stackB_size - (*stackB) -> positionB; 
	int move_rcount;
	if (move_rcounta > move_rcountb) 
		move_rcount = move_rcounta - move_rcountb;
	else 
		move_rcount = move_rcountb - move_rcounta;
	//printf("real sizeb: d\n");
	// printf("%d <= %d\n", (*stackB) -> positionB,((*stackB) -> stackB_size + 1)/ 2);
	if ((*stackB)->cheapest_cost != 1)
	{
		if ((*stackA) -> positionA <= ((*stackA)->stackA_size + 1) / 2
		&& (*stackB) -> positionB <= (*stackB) -> stackB_size / 2) 
		{
			if (((*stackA) -> positionA) > 1 && ((*stackA) -> positionA - 1 ) >= (*stackB) -> positionB
				&& ((*stackA) -> positionA != 2 ||  (*stackB) -> positionB != 2))
			{  
				while (move_countb > 0)
				{
					// printf("YESSSS\n");
					// if ((*stackB) -> positionB == 1 && (*stackA)->target > (*stackB)->first && (*stackB)->first > (*stackB)->next->data) 
					if ((*stackB) -> positionB == 1 && (*stackA)->target > (*stackB)->first && (*stackB)->target < (*stackB)->last)
					{
						// printf("YESSSS\n");
						move_count++;
						break ;
					}
					double_rotate(stackA, stackB);
					printf("rr\n");
					// printf("here\n");
					move_countb--;
				}
				// printf("Ooooooooooooooooooooo move count = %d\n", move_count);
				while (move_count > 0)// || (move_count == 0 && (*stackB) -> positionB == 1))
				{
					if ((*stackA)->target == (*stackA)->data)
						break ;
					// printf("*** %d *** %d\n", (*stackA)->target, (*stackA)->data);
					rotate(stackA);
					printf("ra\n");
					// printf("not here\n");
					move_count--;
					// if (move_count == -1 && (*stackB) -> positionB == 1)
					// 	break ; 
				}
			}
			else
			{
				while (((*stackA) -> positionA) > 1 && move_counta > 0)
				{
					// if (((*stackA) -> positionA - 2) == 0)
					// {
					// 	rotate(stackA);
					// 	printf("ra\n");
					// 	break ;
					// }
					double_rotate(stackA, stackB);
					printf("rr\n");
					move_counta--;
				}
				// while (((*stackB) -> positionB > 1) && move_count > 0)
				// while (((*stackA)->data < (*stackB)->first && (*stackA)->data > (*stackB)->last) && move_count > 0) 
				// while (((*stackA)->data < (*stackB)->first && move_count > 0 && (*stackB)->stackB_size != 2)
				// 	|| (move_count > 0 && (*stackB)->stackB_size == 2 && ((*stackA)->data > (*stackB)->first && (*stackA)->data > (*stackB)->last && (*stackB)->first < (*stackB)->last))
				// 	|| (((*stackB) -> positionB != 1) && move_count > 0)) 
				while(move_count > 0 && (((*stackB) -> positionB== 1 && (*stackB)->stackB_size==2 && !((*stackA)->data > (*stackB)->first && (*stackA)->data < (*stackB)->last)) 
					|| ((((*stackB) -> positionB != 2) && ((*stackB)->stackB_size != 2)) 
					|| !((*stackA) -> positionA == 1 && (*stackB) -> positionB==1 && (*stackA)->data > (*stackB)->first && (*stackA)->data < (*stackB)->last))))
				{
					rotate(stackB);
					printf("rb\n");
					// printf("simply1\n");
					// printf("??? %d\n", move_count);
					// exit(0);
					move_count--;
				}     
				// printf(" -------->>>>>>>>>>>>>>>> %d\n", (*stackB) -> positionB);
				// printf("simply2\n");
			}
		}
		else  if ((*stackB) -> positionB > (*stackB) -> stackB_size / 2
		&& (*stackA) -> positionA <= ((*stackA) ->stackA_size + 1) / 2) 
		{
			while((*stackA) -> positionA > 1 && move_counta > 0)
			{
				rotate(stackA);
				printf("ra\n");
				move_counta--;
			}
			while (move_rcountb > 0)
			{
				reverse_rotate(stackB);
				printf("rrb\n");
				move_rcountb--;
			}
		}   
		else if ((*stackB) -> positionB <= (*stackB) -> stackB_size / 2 
		&& (*stackA) -> positionA > ((*stackA) ->stackA_size + 1) / 2) 
		{
			while ((*stackA) -> positionA > 1 && move_rcounta > 0)
			{
				reverse_rotate(stackA);
				printf("rra\n");
				move_rcounta--;
			}
			// while ((*stackA)->data < (*stackB)->first && move_countb > 0) 
			while (move_countb > 0 && !((*stackA)->target > (*stackB)->first && (*stackA)->data < (*stackB)->last))
			{
				rotate(stackB);
				printf("rb\n");
				move_countb--;
			}
			// printf("hello world\n");
			// printf("%d\n", move_countb);
		}
		else if ((*stackB) -> positionB > (*stackB) -> stackB_size / 2 
		&& (*stackA) -> positionA > ((*stackA) ->stackA_size + 1) / 2) 
		{
			if ((*stackA) -> positionA > 1 && ((*stackA) ->stackA_size + 1) - (*stackA) -> positionA >= (*stackB) ->stackB_size - (*stackB) -> positionB)
			{  

			// 	if ((*stackA) -> positionA > 1 && (*stackA) -> positionA >= (*stackB) -> positionB)
			// { 
			// 	while (move_countb > 0)
			// 	{
			// 		if (move_countb == 1 && move_count == 0 && (*stackA)->target > (*stackB)->first)
			// 		{
			// 			move_count = 1;
			// 			break ;
			// 		}

				while (move_rcountb > 0)
				{
					double_reverse_rotate(stackA, stackB);
					printf("rrr\n");
					move_rcountb--;

					
				} 
				while (move_rcount > 0)
				{
					reverse_rotate(stackA);
					printf("rra\n");
					move_rcount--;
				}
			}
			else 
			{
				while (move_rcounta > 0)
				{
					double_reverse_rotate(stackA, stackB);
					printf("rrr\n");
					move_rcounta--;
				} 
				while (move_rcount > 0)
				{
					reverse_rotate(stackB);
					printf("rrb\n");
					move_rcount--;
				}
			}
		}
	}
		push(stackA, stackB);
		printf("pb\n");  
}

void   rotate_pushback(Node **stacka , Node **stackb)
{
	int position = 1;
	Node *tmp = (*stackb);
	int i = 1;
    listsize((*stacka), (*stackb));
	largestnsmallest((*stackb));
    tmp = (*stackb);

	// firstnlast(stackb);

	while (tmp != NULL)
	{
		if (tmp -> data == tmp ->bmax)
			break;
		position++;
		tmp = tmp ->next;
	}
	tmp = (*stackb);
    // printf("position is = %d\n", position);
    // printf("bmax is = %d\n", tmp ->bmax);
	if (position <= (tmp ->stackB_size + 1) / 2)
	{
		while (i < position)
		{
            rotate(stackb);
			printf("rb\n");
			i++;
        }
	}
	else
	{
		while (position <= tmp ->stackB_size)
		{
            reverse_rotate(stackb);
			printf("rrb\n");
            position++;
        }
	}
    // while (tmp != NULL)
    //     push(stackb, stacka);
} 
 


// void check_if_sorted(Node **stackA, Node **stackB) //rotate to make max at the top, then check if sorted
// {
// 	Node *tmp = (*stackB);
// 	listsize((*stackA), tmp);
// 	largestnsmallest(tmp);
// 	firstnlast(tmp);
// 	int bmax_position = 0;
// 	while (tmp && tmp->data != tmp->bmax) //generalize this, it should not be 100 always
// 	{
// 		tmp = tmp->next;
// 		bmax_position++;
// 	}
// 	tmp = (*stackB);
// 	while (tmp->data != tmp->bmax)
// 	{
// 		if(bmax_position <=  100 / 2) //generalize this, it should not be 100 always
// 		{
// 			rotate(&tmp);
// 			printf("rb\n");
// 		}
// 		else
// 		{
// 			reverse_rotate(&tmp);
// 			printf("rrb\n");
// 		}
// 	}

// 	//now, check if sorted
// 	//
// 	//YOU CAN MODIFY THIS TO temp IF YOU PREFERE THAT :)!
// 	// while (tmp)
// 	// {
// 	// 	if (tmp->data > tmp->next->data)
// 	// 		tmp = tmp->next;
// 	// 	else
// 	// 		break;
// 	// }
// 	// if (tmp)
// 	// 	printf("NOT SORTED! :(\n");
// 	// else
// 	// 	printf("Sorted, Yay!\n");
// }


void mixer(Node **stacka, Node **stackb)
{
	int x = 0;

	while (*stacka != NULL)
	{
		target(*stacka, *stackb);
			// printf("data: %d\n", (*stacka) ->data);
			// printf("targetB: %d\n", (*stackb) ->data);
			// printf("position A: %d\n",(*stacka) ->positionA);
			// printf("position B:%d\n",(*stackb) ->positionB);
			// printf("size A: %d\n",(*stacka) ->stackA_size);
			// printf("size B:%d\n",(*stackb) ->stackB_size); 
			// printf("@@@@@@@@@@@ TARGET : %d\n", (*stacka) -> target);
		makemoves(stacka, stackb);
		// rotate_pushback(stacka, stackb);
		// printf("--------------------------------\n");
		// printlist(*stacka);
			// printf("--------------------------------\n");
			// printlist(*stackb);
			// printf("--------------------------------\n");
		
		// // x++;
		// printf("--------------------------%d--------------------------\n", x);
		// if (x ==30)
		// 	break;
		// target(*stacka, *stackb);
		// 	printf("data: %d\n", (*stacka) ->data);
		// 	//printf("targetB: %d\n", (*stackb) ->data);
		// 	printf("position A: %d\n",(*stacka) ->positionA);
		// 	printf("position B:%d\n",(*stackb) ->positionB);
		// 	printf("size A: %d\n",(*stacka) ->stackA_size);
		// 	printf("size B:%d\n",(*stackb) ->stackB_size); 
		// makemoves(stacka, stackb);
		// // printf("--------------------------------\n");
		// // printlist(*stacka);
		// 	printf("--------------------------------\n");
		// 	printlist(*stackb);
		// 	printf("--------------------------------\n");
		// // 

		// target(*stacka, *stackb);
		// 	printf("data: %d\n", (*stacka) ->data);
		// 	//printf("targetB: %d\n", (*stackb) ->data);
		// 	printf("position A: %d\n",(*stacka) ->positionA);
		// 	printf("position B:%d\n",(*stackb) ->positionB);
		// 	printf("size A: %d\n",(*stacka) ->stackA_size);
		// 	printf("size B:%d\n",(*stackb) ->stackB_size); 
		// makemoves(stacka, stackb);
		// // printf("--------------------------------\n");
		// // printlist(*stacka);
		// 	printf("--------------------------------\n");
		// 	printlist(*stackb);
		// 	printf("--------------------------------\n");
		// // 

		// target(*stacka, *stackb);
		// 	printf("data: %d\n", (*stacka) ->data);
		// 	//printf("targetB: %d\n", (*stackb) ->data);
		// 	printf("position A: %d\n",(*stacka) ->positionA);
		// 	printf("position B:%d\n",(*stackb) ->positionB);
		// 	printf("size A: %d\n",(*stacka) ->stackA_size);
		// 	printf("size B:%d\n",(*stackb) ->stackB_size); 
		// makemoves(stacka, stackb);
		// // printf("--------------------------------\n");
		// // printlist(*stacka);
		// 	printf("--------------------------------\n");
		// 	printlist(*stackb);
		// 	printf("--------------------------------\n");
		// // 

		// target(*stacka, *stackb);
		// 	printf("data: %d\n", (*stacka) ->data);
		// 	//printf("targetB: %d\n", (*stackb) ->data);
		// 	printf("position A: %d\n",(*stacka) ->positionA);
		// 	printf("position B:%d\n",(*stackb) ->positionB);
		// 	printf("size A: %d\n",(*stacka) ->stackA_size);
		// 	printf("size B:%d\n",(*stackb) ->stackB_size); 
		// makemoves(stacka, stackb);
		// // printf("--------------------------------\n");
		// // printlist(*stacka);
		// 	printf("--------------------------------\n");
		// 	printlist(*stackb);
		// 	printf("--------------------------------\n");
		// // 
	}
	// check_if_sorted(stacka, stackb);
    rotate_pushback(stacka, stackb);
	
}

int main(int ac, char **av)
{
	Node *stacka = is_valid(ac, av);
	Node *stackb = NULL;

	push(&stacka, &stackb); 
	printf("pa\n");
	push(&stacka, &stackb);
	printf("pb\n");
	// 462 110 659 -794 -906 302 -370 458 459 548 -252 223 -83 396 398 -9 486 175 375 640 -101 542 986 437 -140 489 759 80 162 273 -789 601 -636 -112 749 625 -671 -132 -873 324 546 -975 -698 -829 2 -839 -970 575 -39 716
	
	// 94 62 -37 41 23 -41 32 -62 -67 -55 55 84 34 -65 85
	// rotate(&stackb);
	// push(&stacka, &stackb);

	// push(&stacka, &stackb);
	
	// target(stacka, stackb);
	//if (stackb -> data > stackb -> next ->data)
	//{   
	//	swap(stackb);
	//	printf("stack b got swapped\n");
	//}
	mixer(&stacka, &stackb);
	while (stackb)
	{
		push(&stackb, &stacka);
		printf("pa\n");
	}
	Node *tmp = stacka;
	while (tmp -> next != NULL)
	{
		if (tmp -> data > tmp -> next-> data)
		{
			printf("alert.....................\n");
			break; 
		}
		tmp = tmp -> next;
	}
	
	// printlist(stacka);
	// rotate_pushback(stacka, stackb);
	// printlist(stackb);
}


// Notes:fix formulas.
// add cost based rrr  
	// is_valid(ac, av);
	// printlist(stacka);
	// largestnsmallest(stacka);
	// firstnlast(stacka);
	// firstnlast(stackb);
	// mixer(stacka, stackb);
	
	// printf("%d", stackb -> data);
// double check formulas
// do a function and update bmin & bmax 
// do a function and update bfirst and blast 
// fix segfault.
// apply the moves based on the smallest cost and print moves 
// check number of moves 
// check leaks
// work on the bonus
// ask friends 

