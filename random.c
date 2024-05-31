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
        printf("%d\n", tmp ->bmin);
		tmp = tmp -> next;
	}
}
void largestnsmallest(Node *list)
{
    Node *tmp = list;
    
    tmp -> bmin = INT_MAX;
    tmp -> bmax = INT_MIN;
    while (tmp != NULL)
    {
        if (tmp -> bmax < tmp -> data)
            tmp -> bmax = tmp -> data;
        if (tmp -> bmin > tmp -> data)
            tmp -> bmin = tmp -> data;
        tmp = tmp -> next;
    } 
}

void firstnlast(Node *stack)
{
    Node *lastpointer = lastnode(stack);
    
    lastpointer ->last = lastpointer -> data;
    Node *firstpointer = stack;
    firstpointer -> first = stack -> data;
}

void target(Node *stackA, Node *stackB)
{
    Node *tmpA = stackA;
    Node *tmpB = stackB;
    int  cheapest_cost;
    int  target;
    int positionA;
    int positionB;
    int stackA_size = tmpA -> stackA_size;
    int stackB_size = tmpB -> stackB_size;
    int cost;

    positionA = 0;
    cheapest_cost = INT_MAX;

    largestnsmallest(stackB);
    firstnlast(stackB);

    while (tmpA != NULL)
    {
        positionA++;
        positionB = 1;
        tmpB = stackB;
        while (tmpB != NULL)
        {
            if ((tmpB->next != NULL)
            && (tmpA -> data < tmpB -> data    // inbetween.
            && tmpA -> data > tmpB->next->data) 
            || (tmpB -> data == tmpB -> bmax) 
            && (tmpA -> data > tmpB -> bmax || tmpA -> data < tmpB -> bmin) 
            ||  (tmpA -> data > tmpB -> first
            && tmpA -> data < tmpB-> last))
            {
                if (positionA <= (stackA_size + 1) / 2)
                {
                    if (positionB <= (stackB_size + 1) / 2)
                        {
                            if (positionA >= positionB)
                                cost = positionA;
                            else
                                cost = positionB + 1;
                        } //I  might need to subtract 1 move
                    else
                        cost = positionA + stackB_size - positionB; //I  might need to add 1, 1 missing move
                }
                else
                {
                    if (positionB <= (stackB_size + 1) / 2) // should I add one or  not
                        cost = (stackA_size + 2) - positionA + positionB;
                    else
                        {
                            if ((stackA_size + 2) - positionA >= stackB_size - positionB)
                                cost = (stackA_size + 2) - positionA; 
                            else
                                cost = (stackB_size - positionB) + 1;
                        }
                }                 
                if (cost < cheapest_cost)
                {
                    cheapest_cost = cost;
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
        tmpA -> stackA_size = stackA_size;
        tmpB -> stackB_size = stackB_size; //modify it
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
    // target(stacka, stackb);
    
    largestnsmallest(stacka);
    // firstnlast(stackb);
    // mixer(stacka, stackb);
    // printlist(stacka); 
    printf("%d", stackb -> data);
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

