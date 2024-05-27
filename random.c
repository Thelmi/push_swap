#include "list.h"
int target(Node *stackA, Node *stackB)
{
    Node *tmpA = stackA;
    Node *tmpB = stackB;
    int  cheapest_cost;
    int  target;
    int positionA;
    int positionB;
    int stackA_size;
    int stackB_size;

    positionA = 0;
    cheapest_cost = INT_MAX;
    int cost;
    while (tmpA != NULL)
    {
        positionA++;
        positionB = 0;
        tmpB = stackB;
        while (tmpB != NULL)
        {
            if ((tmpA -> data < tmpB -> data    // inbetween.
                && tmpA -> data > tmpB->next->data) // beautiful segfault
                || (tmpB -> data == bmax && (tmpA -> data > bmax || tmpA -> data < bmin)) 
                ||  (tmpA -> data > tmpB -> first
                && tmpA -> data < tmpB-> last))
            {
                if (positionA <= (stackA_size + 1) / 2)
                {
                    if (positionB <= (stackB_size + 1) / 2)
                        cost = positionA + positionB; //we might need to subtract 1 move
                    else
                        cost = positionA + stackB_size - positionB; //we might need to add 1, 1 missing move
                }
                else
                {
                    if (positionB <= (stackB_size + 1) / 2) // should I add one or  not
                        cost = (stackA_size + 2) - positionA + positionB;
                    else
                        cost = (stackA_size + 2) - positionA + (stackB_size + 2) - positionB;
                }                //  11 - 7 + 10 - 5 // it should be 6 however 9
                if (cost < cheapest_cost)
                {
                    cheapest_cost = cost;
                    target = tmpA -> data;
                }
                break ;
            }
            positionB++;
            tmpB = tmpB -> next;            
        }
        tmpA = tmpA -> next;
    }
        // return (target);

        return (); //modify it
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