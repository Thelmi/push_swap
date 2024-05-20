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
                     

       
    //     2            11
    //     3             7
    //     4             5  
    //     5             4 
    //     7              3
    //    11            
                                         
               
