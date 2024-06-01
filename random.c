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
        printf("data: %d\n first: %d\n last: %d\n",tmp ->data ,tmp ->first, tmp ->last);
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
void target(Node *stackA, Node *stackB)
{
    Node *tmpA = stackA;
    Node *tmpB = stackB;
    int  cheapest_cost = INT_MAX;
    int  target = 0;
    int positionA = 0;
    int positionB = 0;
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
        positionB++;
        tmpB = stackB;
        while (tmpB != NULL)
        {
            // if ((tmpB->next != NULL)
            // && (tmpA -> data < tmpB -> data) && (tmpA -> data > tmpB->next->data)
            // || (tmpB -> data == tmpB -> bmax) 
            // && (tmpA -> data > tmpB -> bmax) || (tmpA -> data < tmpB -> bmin)
            // ||  (tmpA -> data > tmpB -> first && tmpA -> data < tmpB-> last))
            if ((tmpB->next != NULL) 
            && ((tmpA->data < tmpB->data && tmpA->data > tmpB->next->data) 
            || (tmpB->data == tmpB->bmax && tmpA->data > tmpB->bmax)
            || (tmpA->data < tmpB->bmin) 
            || (tmpA->data > tmpB->first && tmpA->data < tmpB->last)))

            {
                if (positionA <= (tmpA ->stackA_size + 1) / 2)
                {
                    if (positionB <= (tmpB ->stackB_size + 1) / 2)
                        {
                            if (positionA > positionB)
                            {
                                cost = positionA;
                                // printf("1) cost: %d = positionA %d\n",cost, positionA);
                            }
                            else
                            {
                                cost = positionB + 1;
                                //  printf("2) cost: %d = positionB: %d + 1\n",cost, positionB);
                            }
                        } //  might need to subtract 1 mov
                    else
                        {
                            cost = positionA + (tmpB ->stackB_size - positionB);
                            // printf("3) cost: %d = postionA: %d +(tmpB ->stackB_size: %d - postionB: %d\n)",cost, positionA,tmpB ->stackB_size, positionB);
						}  //I  might need to add 1, 1 missing move
                }
                else
                {
                    if (positionB <= (tmpB->stackB_size + 1) / 2)
                    { // should I add one or  not
                        cost = (tmpA ->stackA_size + 2) - positionA + positionB;
                        // printf("4) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d + positionB: %d\n", cost, tmpA -> stackA_size +2, positionA, positionB);
                    }
                    else
                        {
                            if ((tmpA ->stackA_size + 2) - positionA > tmpB ->stackB_size - positionB)
                            {
                                cost = (tmpA -> stackA_size + 2) - positionA;
                                //  printf("5) cost: %d = (tmpA -> stackA_size + 2: %d) - positionA: %d", cost, tmpA -> stackA_size + 2, positionA);
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
                    // printf("%d\n",cheapest_cost);
                    target = tmpA -> data;
                    tmpA -> target = target;
                    tmpA ->positionA = positionA;
                    tmpB -> positionB = positionB;
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
}

void makemoves(Node *stackA, Node *stackB)
{
    Node *tmp = stackA;

    int move_counta = tmp -> positionA - 1;
    int move_countb = tmp -> positionB;
    int move_count = move_counta - move_countb;

    int move_rcounta = (tmp -> stackA_size + 1) - tmp -> positionA;
    int move_rcountb = tmp -> stackB_size - move_countb; 
    int move_rcount = move_rcounta - move_rcountb;

    if (tmp ->positionA <= (tmp ->stackA_size + 1) / 2)
    {
        if (tmp ->positionB <= (tmp -> stackB_size + 1) / 2)
            {
                if (tmp ->positionA >= tmp -> positionB)
                { 
                    while (move_countb > 0)
                    {
                        double_rotate(stackA, stackB);
                        printf("rr");
                        move_countb--;
                    }
                    while (move_count > 0)
                    {
                        rotate(stackA);
                        printf("ra");
                        move_count--;
                    }
                    push(&stackA, &stackB);
                    printf("pb"); 
                }
                else
                {
                    while (move_counta > 0)
                    {
                        double_rotate(stackA, stackB);
                        printf("rr");
                        move_counta--;
                    }
                    while (move_count > 0)
                    {
                        rotate(stackB);
                        printf("rb");
                        move_count--;
                    }
                    push(&stackA, &stackB);
                    printf("pb");
                 }
            }
        else
        {
            while(move_counta > 0)
            {
                rotate(stackA);
                printf("ra");
                move_counta--;
            }
            while (move_rcountb > 0)
            {
                reverse_rotate(&stackB);
                printf("rrb");
                move_rcountb--;
            }
            push(&stackA, &stackB);
            printf("pb");
         }    //I  might need to add 1, 1 missing move
    }
    else
    {
        if (tmp ->positionB <= (tmp -> stackB_size + 1) / 2) // should I add one or  not
           { // cost = (stackA_size + 2) - positionA + positionB;
            while (move_countb > 0)
            {
                rotate(stackB);
                printf("rb");
                move_countb--;
            }
            while (move_rcounta > 0)
            {
                reverse_rotate(&stackA);
                printf("rra");
                move_rcounta--;
            }
            push(&stackA, &stackB);
            printf("pb");
           }
        else
            {
                if ((tmp ->stackA_size + 2) - tmp -> positionA >= tmp ->stackB_size - tmp -> positionB)
                  {  
                    while (move_rcountb > 0)
                    {
                        double_reverse_rotate(&stackA, &stackB);
                        printf("rrr");
                        move_rcountb--;
                    } 
                    while (move_rcount > 0)
                    {
                        reverse_rotate(&stackA);
                        printf("rra");
                        move_rcount--;
                    }
                    push(&stackA, &stackB);
                    printf("pa");
                  } 
                else
                {
                 while (move_rcounta > 0)
                    {
                        double_reverse_rotate(&stackA, &stackB);
                        printf("rrr");
                        move_rcounta--;
                    } 
                    while (move_rcount > 0)
                    {
                        reverse_rotate(&stackB);
                        printf("rr");
                        move_rcount--;
                    }
                    push(&stackA, &stackB);
                    printf("%s", "pa");
                }
            }
    }                 
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

void mixer(Node *stacka, Node *stackb)
{
    int size = stacka -> stackA_size;

    while(size)
    {
        target(stacka, stackb);
        size--;
    }
    while (stackb != NULL)
    {
        makemoves(stacka, stackb);
       while (stacka != NULL)
        {
            rotate_pushback(stacka, stackb);
        }
    }
}
int main(int ac, char **av)
{
    Node *stacka = is_valid(ac, av);
    Node *stackb = NULL;
    push(&stacka, &stackb);
    push(&stacka, &stackb);
    // mixer(stacka, stackb);
    // makemoves(stacka, stackb);
    target(stacka, stackb);
    
    // largestnsmallest(stacka);
	// firstnlast(stacka);
    // firstnlast(stackb);
    // mixer(stacka, stackb);
    // printlist(stackb); 
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

