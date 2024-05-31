// 1) Array into a linked list
// 2) add_back
// 3) add_front
// 4) add_node on a certain order
// 5) add_node after a certain value
// 6) free the head
// 7) free the tail
// 8) free based on their order
// 9) free based on its value.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct list
// {
//     int data;
//     struct list* next;
    
// }              Node;
// Node* createNode(int value)
// {
//     Node* newnode = malloc(sizeof(Node));
//     newnode -> data = value;
//     newnode -> next = NULL;
//     return newnode;
// }
// void printlist(Node* head)
// {
//     Node* tmp = head;
//     while (tmp != NULL)
//     {
//         printf("%d\n",tmp -> data);
//         tmp = tmp -> next;
//     }
// }
// void freelist(Node* list)
// {
//     Node *tmp = list;
//     while(tmp != NULL)
//     {
//         tmp = list -> next;
//         free(list);
//         list = tmp;
//     }
// }
// Node* arrtolist(int *arr, int size)
// {
//     if (!arr)
//         return NULL;
//     Node* head = createNode(arr[0]);
//     Node* connect = head;
//     int i = 1;
//     while (i < size)
//     {
//         Node* tmp = createNode(arr[i]);
//         connect -> next = tmp;
//         connect = tmp;
//         i++;
//     }
//         return (head);
// }
// // int main()
// // {
// //     int arr[7] = {1, 2, 3 , 4 , 5};
// //     int size = sizeof(arr) / sizeof(arr[0]);
// //     Node* list = arrtolist(arr, size);
// //     printlist(list);
// //     freelist(list);
// // }

// part2 

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
    
}              Node;

Node* createNode(int value)
{
    Node* newnode = malloc(sizeof(Node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}
// void printlist(Node* head)
// {
//     Node* tmp = head;
//     while (tmp != NULL)
//     {
//         printf("%d\n",tmp -> data);
//         tmp = tmp -> next;
//     }
// }
void freelist(Node* list)
{
    Node *tmp = list;
    while(tmp != NULL)
    {
        tmp = list -> next;
        free(list);
        list = tmp;
    }
}

Node** addfront(Node** head, int value)
{
    Node *newnode = createNode(value);
    newnode -> next = *head;
    *head = newnode;
    return head;
}
Node* addback(Node* head, int value)
{
    Node *newnode = createNode(value);
    Node *tmp = head;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = newnode;
        return head;
}
int main()
{
    Node *head = createNode(2);
    addfront(&head, 1);
    addback(head, 3);
    printlist(head);
}