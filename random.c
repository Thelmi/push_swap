// #include "list.h"
// int target(Node *stackA, Node *stackB)
// {
//     Node *tmpA = stackA;
//     Node *tmpB = stackB;
//     int  cheapest_cost;
//     int  target;
//     int positionA;
//     int positionB;
//     int stackA_size;
//     int stackB_size;

//     positionA = 0;
//     cheapest_cost = INT_MAX;
//     int cost;
//     while (tmpA != NULL)
//     {
//         positionA++;
//         positionB = 0;
//         tmpB = stackB;
//         while (tmpB != NULL)
//         {
//             if ((tmpA -> data < tmpB -> data    // inbetween.
//                 && tmpA -> data > tmpB->next->data) // beautiful segfault
//                 || (tmpB -> data == bmax && (tmpA -> data > bmax || tmpA -> data < bmin)) 
//                 ||  (tmpA -> data > tmpB -> first
//                 && tmpA -> data < tmpB-> last))
//             {
//                 if (positionA <= (stackA_size + 1) / 2)
//                 {
//                     if (positionB <= (stackB_size + 1) / 2)
//                         cost = positionA + positionB; //I  might need to subtract 1 move
//                     else
//                         cost = positionA + stackB_size - positionB; //I  might need to add 1, 1 missing move
//                 }
//                 else
//                 {
//                     if (positionB <= (stackB_size + 1) / 2) // should I add one or  not
//                         cost = (stackA_size + 2) - positionA + positionB;
//                     else
//                         cost = (stackA_size + 2) - positionA + (stackB_size) - positionB;
//                 }                 
//                 if (cost < cheapest_cost)
//                 {
//                     cheapest_cost = cost;
//                     target = tmpA -> data;
//                 }
//                 break ;
//             }
//             positionB++;
//             tmpB = tmpB -> next;            
//         }
//         tmpA = tmpA -> next;
//     }
//         // return (target);

//         return (); //modify it
// }

#include "list.h"
#include <stdio.h>
void printlist(Node* list)
{
	Node *tmp = list;
	while (tmp != NULL)
	{
		// printf("data: %d\n max: %d\n min: %d\n ", tmp -> data, tmp ->bmax, tmp -> bmin);
		// printf("data: %d\n first: %d\n last: %d\n",tmp ->data ,tmp ->first, tmp ->last);
		printf("data: %d\n", tmp ->data);
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
void listsize(Node *stacka , Node *stackb)
{
	Node *tmp = stacka;
	int count = 0;
	while (tmp != NULL)
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
		tmp = tmp -> next;
	}
	tmp = stackb;
	while (tmp != NULL)
	{
		tmp ->positionB = positionb;
		tmp = tmp -> next;
	}
}
void target(Node *stackA, Node *stackB)
{
	Node *tmpA = stackA;
	Node *tmpB = stackB;
	int  cheapest_cost = INT_MAX;
	int  target = 0;
	int positionA = 0;
	int positionB = 1;
	int cost = 0;
	// int stackA_size = 0;
	// int stackB_size = 0;
	
	// stackA_size = stackA -> stackA_size;
	// stackB_size = stackB -> stackB_size;
	// cheapest_cost = INT_MAX;

	listsize(stackA, stackB);
	// printf("%d\n", stackA -> stackA_size);
	// printf("%d\n", stackB -> stackB_size);
	largestnsmallest(stackB);
	firstnlast(stackB);

	while (tmpA != NULL)
	{
		positionA++;
		 
		tmpB = stackB;
		while (tmpB != NULL)
		{
			// if ((tmpB->next != NULL)
			// && (tmpA -> data < tmpB -> data) && (tmpA -> data > tmpB->next->data)
			// || (tmpB -> data == tmpB -> bmax) 
			// && (tmpA -> data > tmpB -> bmax) || (tmpA -> data < tmpB -> bmin)
			// ||  (tmpA -> data > tmpB -> first && tmpA -> data < tmpB-> last))
			if ((tmpB->next != NULL
			&& (tmpA->data < tmpB->data && tmpA->data > tmpB->next->data))
			|| (tmpB->data == tmpB->bmax) && (tmpA->data > tmpB->bmax
			|| tmpA->data < tmpB->bmin) 
			|| (tmpA->data > tmpB->first && tmpA->data < tmpB->last))
			{
				//printf("%d\n", positionB);
				//printf("ay xay\n");
				//exit(0);
				if (positionA <= (tmpA ->stackA_size + 1) / 2)
				{
					if (positionB <= (tmpB ->stackB_size + 1) / 2)
						{
							if (positionA == 1 && positionB == 1)
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
								cost = positionB;
								//  printf("2) cost: %d = positionB: %d + 1\n",cost, positionB);
							}
						} //  might need to subtract 1 mov
					else
						{
							if (positionB == 2 && stackB ->stackB_size == 2)
									cost = positionA + ((tmpB ->stackB_size + 1) - positionB);
							else
							{
							cost = positionA + (tmpB ->stackB_size - positionB);
							// printf("3) cost: %d = postionA: %d +(tmpB ->stackB_size: %d - postionB: %d\n)",cost, positionA,tmpB ->stackB_size, positionB);
							}
						}  //I  might need to add 1, 1 missing move
				}
				else
				{
					if (positionB <= (tmpB->stackB_size + 1) / 2)
					{ // should I add one or  not
						if (stackB ->stackB_size == 2)
								positionB--;
						cost = (tmpA ->stackA_size + 2) - positionA + positionB;
						// printf("4) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d + positionB: %d\n", cost, tmpA -> stackA_size +2, positionA, positionB);
					}
					else
						{
							if ((tmpA ->stackA_size + 2) - positionA > tmpB ->stackB_size - positionB)
							{
								cost = (tmpA -> stackA_size + 2) - positionA;
								//  printf("5) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d\n", cost, tmpA -> stackA_size + 2, positionA);
							} 
							else
							{
								cost = (tmpB ->stackB_size - positionB);
								//  printf("6) cost: %d = (tmpB -> stackA_size: %d - positionB +1: %d\n)", cost, tmpB -> stackB_size, positionB + 1);
							}
						}
				}                 
				if (cost < cheapest_cost)
				{
					cheapest_cost = cost;
					// printf("cheapest cost: %d\n",cheapest_cost);
					target = tmpA -> data;
					tmpA -> target = target;

					tmpA ->positionA = positionA;
					tmpB -> positionB = positionB;
					//printf("I entered: %d\n", positionB);
					//exit(0);
					//printf("%d\n", positionB);
					//printf("ay xay\n");
					//exit(0);
					printf("first: %d\n", tmpB ->first);
					printf("last: %d\n", tmpB ->last);
			
					printf("bmax:%d\n",tmpB->bmax);
					positionab(stackA, stackB, positionA, positionB);
				}
				break;
			}
			positionB++;
			tmpB = tmpB -> next;        
		}
		tmpA = tmpA -> next;
	}
	// printf("%d",cheapest_cost);
		// tmpA -> stackA_size = stackA_size;
		// tmpB -> stackB_size = stackB_size; 
		printf("cheapest cost: %d\n",cheapest_cost);
}

// void makemoves(Node *stackA, Node *stackB)
// {
	
//     Node *tmp = stackA;
//     target(stackA, stackB);
//     printf("positiona: %d, postionb: %d\n", stackA ->positionA, stackB ->positionB);
//     int move_counta = tmp -> positionA - 1;
//     int move_countb = tmp -> positionB;
//     int move_count = move_counta - move_countb;

//     int move_rcounta = (tmp -> stackA_size + 1) - tmp -> positionA;
//     int move_rcountb = tmp -> stackB_size - move_countb; 
//     int move_rcount = move_rcounta - move_rcountb;

	
//         if (tmp ->positionA <= (tmp ->stackA_size + 1) / 2)
//         {
//             if (tmp ->positionB <= (tmp -> stackB_size + 1) / 2)
//                 {
//                     if (tmp ->positionA >= tmp -> positionB)
//                     { 
//                         while (move_countb > 0)
//                         {
//                             double_rotate(stackA, stackB);
//                             printf("rr\n");
//                             move_countb--;
//                         }
//                         while (move_count > 0)
//                         {
//                             rotate(stackA);
//                             printf("ra\n");
//                             move_count--;
//                         }
//                         push(&stackA, &stackB);
//                         printf("pb\n"); 
//                     }
//                     else
//                     {
//                         while (move_counta > 0)
//                         {
//                             double_rotate(stackA, stackB);
//                             printf("rr\n");
//                             move_counta--;
//                         }
//                         while (move_count > 0)
//                         {
//                             rotate(stackB);
//                             printf("rb\n");
//                             move_count--;
//                         }
//                         push(&stackA, &stackB);
//                         printf("pb\n");
//                     }
//                 }
//             else
//             {
//                 while(move_counta > 0)
//                 {
//                     rotate(stackA);
//                     printf("ra\n");
//                     move_counta--;
//                 }
//                 while (move_rcountb > 0)
//                 {
//                     reverse_rotate(&stackB);
//                     printf("rrb\n");
//                     move_rcountb--;
//                 }
//                 push(&stackA, &stackB);
//                 printf("pb\n");
//             }    //I  might need to add 1, 1 missing move
//         }
//         else
//         {
//             if (tmp ->positionB <= (tmp -> stackB_size + 1) / 2) // should I add one or  not
//             { // cost = (stackA_size + 2) - positionA + positionB;
//                 while (move_countb > 0)
//                 {
//                     rotate(stackB);
//                     printf("rb\n");
//                     move_countb--;
//                 }
//                 while (move_rcounta > 0)
//                 {
//                     reverse_rotate(&stackA);
//                     printf("rra\n");
//                     move_rcounta--;
//                 }
//                 push(&stackA, &stackB);
//                 printf("pb\n");
//             }
//             else
//                 {
//                     if ((tmp ->stackA_size + 2) - tmp -> positionA >= tmp ->stackB_size - tmp -> positionB)
//                     {  
//                         while (move_rcountb > 0)
//                         {
//                             double_reverse_rotate(&stackA, &stackB);
//                             printf("rrr\n");
//                             move_rcountb--;
//                         } 
//                         while (move_rcount > 0)
//                         {
//                             reverse_rotate(&stackA);
//                             printf("rra\n");
//                             move_rcount--;
//                         }
//                         push(&stackA, &stackB);
//                         printf("pa\n");
//                     } 
//                     else
//                     {
//                     while (move_rcounta > 0)
//                         {
//                             double_reverse_rotate(&stackA, &stackB);
//                             printf("rrr\n");
//                             move_rcounta--;
//                         } 
//                         while (move_rcount > 0)
//                         {
//                             reverse_rotate(&stackB);
//                             printf("rr\n");
//                             move_rcount--;
//                         }
//                         push(&stackA, &stackB);
//                         printf("pa\n");
//                     }
//                 }
//         }               
// }

void makemoves(Node **stackA, Node **stackB)
{
	// Node *tmp = stackA;
	// target(stackA, stackB);
	// printf("positiona: %d, postionb: %d\n", stackA -> positionA, stackB -> positionB);

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
	if (move_rcounta > move_countb)
		move_rcount = move_rcounta - move_rcountb;
	else 
		move_rcount = move_rcountb - move_rcounta;

		if ((*stackA) -> positionA <= (*stackA) ->stackA_size + 1 / 2
		&& (*stackB) -> positionB <= (*stackB) -> stackB_size + 1 / 2)
		{
			if ((*stackA) -> positionA > 1 && (*stackA) -> positionA >= (*stackB) -> positionB)
			{ 
				while (move_countb > 0)
				{
					double_rotate(*stackA, *stackB);
					printf("rr\n");
					move_countb--;
				}
				while (move_count > 0)
				{
					rotate(*stackA);
					printf("ra\n");
					move_count--;
				}
			}
			else
			{
				while ((*stackA) -> positionA > 1 && move_counta > 0)
				{
					double_rotate(*stackA, *stackB);
					printf("rr\n");
					move_counta--;
				}
				while (((*stackA) -> positionA != 1 || (*stackB) -> positionB != 1) && move_count > 0)
				{
					rotate(*stackB);
					printf("rb\n");
					// printf("simply\n");
					move_count--;
				}     
			}
		}
		else  if ((*stackB) -> positionB > ((*stackB) -> stackB_size + 1) / 2
		&& (*stackA) -> positionA <= ((*stackA) ->stackA_size + 1) / 2)
		{
			while((*stackA) -> positionA > 1 && move_counta > 0)
			{
				rotate(*stackA);
				printf("ra\n");
				move_counta--;
			}
			while (move_rcountb > 0)
			{
				reverse_rotate(stackB);
				printf("rrb\n");
				move_rcountb--;
			}
		}    //I  might need to add 1, 1 missing move
		else if ((*stackB) -> positionB <= ((*stackB) -> stackB_size + 1) / 2 
		&& (*stackA) -> positionA > ((*stackA) ->stackA_size + 1) / 2)
		{
			while (move_countb > 0)
			{
				rotate(*stackB);
				printf("rb\n");
				move_countb--;
			}
			while ((*stackA) -> positionA > 1 && move_rcounta > 0)
			{
				reverse_rotate(stackA);
				printf("rra\n");
				move_rcounta--;
			}
		}
		else if ((*stackB) -> positionB > ((*stackB) -> stackB_size + 1) / 2 
		&& (*stackA) -> positionA > ((*stackA) ->stackA_size + 1) / 2)
		{
			if ((*stackA) -> positionA > 1 && ((*stackA) ->stackA_size + 2) - (*stackA) -> positionA >= (*stackB) ->stackB_size - (*stackB) -> positionB)
			{  
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

		push(stackA, stackB);
		printf("push\n");








	//     else
	//     {
	//         while (stackA -> positionA > 1 && move_rcounta > 0)
	//         {
	//             double_reverse_rotate(&stackA, &stackB);
	//             printf("rrr\n");
	//             move_rcounta--;
	//         }       
	//         while (stackA -> positionA > 1 && move_rcount > 0)
	//         {
	//             reverse_rotate(&stackB);
	//             printf("rr\n");
	//             move_rcount--;
	//         }
	//     }
	
		// push(&stackA, &stackB);
		// printf("push me: pb\n");
		// printlist(stackA);
	//     break;    
}

void   rotate_pushback(Node *stacka , Node *stackb)
{
	int position = 1;
	Node *tmp = stackb;

	while (tmp != NULL)
	{
		if (tmp -> data == tmp ->bmax)
			break;
		position++;
		tmp = tmp ->next;
	}
	tmp = stackb;
	if (position >= tmp ->stackA_size + 1 / 2)
	{
		while (tmp -> data == tmp ->bmax)
			rotate(stackb);
	}
	else
	{
		while (tmp -> data == tmp ->bmax)
			reverse_rotate(&stackb);
		while (tmp != NULL)
			push(&stackb, &stacka);
	}
} 


void mixer(Node **stacka, Node **stackb)
{
	// int size = stacka -> stackA_size;

	// while(size)
	// {
	//     target(stacka, stackb);
	//     size--;
	// }
	while (*stacka != NULL)
	{
		target(*stacka, *stackb);
		printf("data: %d\n", (*stacka) ->data);
		//printf("targetB: %d\n", (*stackb) ->data);
		printf("position A: %d\n",(*stacka) ->positionA);
		printf("position B:%d\n",(*stackb) ->positionB);
		printf("size A: %d\n",(*stacka) ->stackA_size);
		printf("size B:%d\n",(*stackb) ->stackB_size); 
		makemoves(stacka, stackb);
		// push(stacka, stackb);
		// printf("hola\n");
	}
	// while (stackb != NULL)
	// {
	//     rotate_pushback;
	// }
	// push(stacka, stackb);
}

int main(int ac, char **av)
{
	Node *stacka = is_valid(ac, av);
	Node *stackb = NULL;

	push(&stacka, &stackb); 
	// printf("pb\n");
	push(&stacka, &stackb);
	//rotate(stackb);
	//push(&stacka, &stackb);
	// printf("pb\n");

	//if (stackb -> data > stackb -> next ->data)
	//{   
	//	swap(stackb);
	//	printf("stack b got swapped\n");
	//}

	// push(&stacka, &stackb);
	// printf("pb");
	// push(&stacka, &stackb);
	// push(&stacka, &stackb);
	// push(&stacka, &stackb);
	// push(&stacka, &stackb);
	// push(&stacka, &stackb);
	mixer(&stacka, &stackb);


	// target(stacka, stackb);
	// makemoves(stacka, stackb);
	printlist(stackb);
	// is_valid(ac, av);
	// printlist(stacka);
	// largestnsmallest(stacka);
	// firstnlast(stacka);
	// firstnlast(stackb);
	// mixer(stacka, stackb);
	
	// printf("%d", stackb -> data);
}

// Notes:fix formulas.
// add cost based rrr  
// double check formulas
// do a function and update bmin & bmax 
// do a function and update bfirst and blast 
// fix segfault.
// apply the moves based on the smallest cost and print moves 
// check number of moves 
// check leaks
// work on the bonus
// ask friends 

