#include "list.h"


// 	while(i < ac)
// 	{
// 		if (t_defence(av[i]) && isnot_term(av[i]))
// 		{
// 			if (ft_strchr(av[i], ' '))
// 			{
// 				splitted = ft_split(av[i], ' ');
// 				if(!head)
// 				{
// 			    	head = createNode(ft_atoi(splitted[0]));
// 					tmp = head;
// 					j = 1;
// 				}
// 				while (splitted[j])
// 				{
// 					nextnode = createNode(ft_atoi(splitted[j]));
// 					tmp -> next = nextnode;
// 					tmp = tmp -> next;
// 					j++;
// 				}
// 				j = 0;
// 				while (splitted[j])
// 				{
// 					free(splitted[j]);
// 					j++;
// 				}
// 				free(splitted);
// 				j = 0;
// 			}
// 			else 
// 			{
// 				if(!head)
// 				{
// 					head = createNode(ft_atoi(av[i]));
// 					tmp = head;
// 				}
// 				else 
// 				{
// 					nextnode = createNode(atoi(av[i]));
// 					tmp -> next = nextnode;
// 					tmp = nextnode;
// 				}
// 			}
// 		}
// 		else 
// 		{
// 			printf("error\n");
// 			freelist(head);
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	isdouble(head);
// 	printlist(head);
// 	freelist(head);
// }

int target(Node *stackA, Node *stackB)
{
    Node *tmpA = stackA;
    Node *tmpB = stackB;
    int  cost;
    int  target;
    while (tmpA != NULL)
    {
        while (tmpB != NULL)
        {
            if (tmpB -> data < tmpA -> data)
            {
                target = tmpB -> data;
                break;
            }
            else 
                target = tmpB -> data;
        }
        tmpA = tmpA -> next;
    }
        return (target);
}
int main(int ac, char **av)
{
    Node *stackA = is_valid(ac, av);
    Node *stackB = NULL;
    push(&stackA, &stackB);
    push(&stackA, &stackB);
    printlist(stackA);
}

// push two random values from stack a to stack b
// and then specify target to each one that u will put value above
// target = stacka > stackb && the least difference 
// if value in stack_a is the samllest the target above the largest value
                     
    //        rotate                                      rr
    //    position / 2 <= size stackb /2        position > size stackb / 2            cost of sorting stack b = size of stackb + 1 - target position

                    
    //      2            11
    //     3
        //    6
        //    7             7
    //     4             5  
    //     5             3 
    //     7             2 
    //    11            
                                         
     

// if head -> data = the one we want to push 
// cost stack a = 0 
//                                                   reverse_rotate = positon of one u want to raise > size stackb / 2 
//                                                   rotate  = positon of one u want to raise < size stackb / 2
// else if (reverse rotate)

// this is the formula (for stacka cost of tranfer to header =  size of stacka + 1 - the one to raise position)

// else if(rotate)

// this is the formula (for stacka cost of tranfer to header = the one to raise position - 1)


// cost = for stacka cost of tranfer to header + cost of sorting stack b;

// the smallest cost is the chosen one to do.