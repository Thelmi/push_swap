#include "list.h"
#include <stdio.h>
// Node *createNode(int value)
// {
//     Node *newnode = malloc(sizeof(Node*));
//     if (!newnode)
//         return NULL;
//     newnode -> data = value;
//     newnode -> next = NULL;
//     return newnode;
// }
// // void printlist(Node *list)
// // {
// //     Node *tmp = list;
// //     while (tmp != NULL)
// //     {
// //         printf("%d\n", tmp ->data);
// //         tmp = tmp -> next;
// //     }
// }
Node *lastnode(Node *list)
{
    Node* tmp = list;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    return(tmp);
}
// swap  

void swap(Node *list)
{
   int swp = list -> data;
   list -> data = list -> next -> data;
   list -> next -> data = swp;

//    printf("%s\n", move);
}
void double_swap(Node *listA, Node *listB)
{
    // int swp = listA -> data;
    // listA -> data = listA -> next -> data;
    // listA -> next -> data = swp;

    // swp = listB -> data;
    // listB -> data = listB -> next -> data;
    // listB -> next -> data = swp;
    swap(listA);
    swap(listB);
    printf("ss\n");
}
// push 
void push(Node **listA, Node **listB)
{
    Node *tmp = *listA;
    *listA = (*listA) -> next;
        tmp -> next = *listB;
    *listB = tmp;
}

// rotate
void rotate(Node **list)
{
    Node *first = *list;
	Node *last = lastnode(*list);
	*list = first -> next;
	first -> next = NULL;
	last -> next =  first;
}
//void rotate(Node *list)
//{
//	Node *tmp = list;

//}

void double_rotate(Node **listA, Node **listB)
{
    rotate(listA);
    rotate(listB);
}
// reverse rotate 
// void reverse_rotate(Node *list)
// {
    //  Node *tmp = list;
    // Node* last = lastnode(list);
    // int swp;
    // while(tmp -> next != NULL)
    // {
    //     if (tmp -> data == list -> data)
    //     {
    //         swp = last -> data;
    //         last -> data = tmp -> data;
    //         tmp -> data = swp;
    //     }
    //     else 
    //     {
    //         swp = tmp ->next -> data;
    //         tmp ->next -> data = tmp->data;
    //         tmp-> data = swp;
    //     }
    //  tmp = tmp -> next;
//     }
// }

void reverse_rotate(Node **list)
{
    Node *tmp = *list;
    Node *last = lastnode(*list);
    
    while (tmp->next->next != NULL)
        tmp = tmp -> next;
    tmp -> next = NULL;
    last -> next = *list;
   *list = last;
}
void double_reverse_rotate(Node **listA, Node **listB)
{
    reverse_rotate(listA);
    reverse_rotate(listB);
}

// int main()
// {
//     Node *head = createNode(1);
//     head -> next = createNode(2);
//     head -> next -> next = createNode(3);
//     head -> next -> next -> next = createNode(4);
//     head -> next -> next -> next -> next = createNode(5);
//     head -> next -> next -> next -> next -> next = createNode(6);
    
//     Node *list = createNode(1);
//     list -> next = createNode(2);
//     list -> next -> next = createNode(3);
//     list -> next ->next ->next = createNode(4);
//     // list -> next -> next->next -> next = createNode(5);
//     // list -> next -> next->next -> next -> next = createNode(6);

//     // Node *list2 = createNode(1);
//     // head -> next = createNode(2);
//     // head -> next -> next = createNode(3);
//     // head -> next -> next -> next = createNode(4);
//     // head -> next -> next -> next -> next = createNode(5);
//     // head -> next -> next -> next -> next -> next = createNode(6);

//     // swap(head,"swap");
//     // double_swap(head,list);
//     // push(&head,&list);
//     reverse_rotate(&head);
//     // double_rotate(head, list);
//     printlist(head);
//     printf("\n");
//     // printlist(list);
// }