 
// typedef struct money
// {

//     char*    name;
//     int      income;
//     int      expenses;
//     char*    assets;                                                                                       
//     char*   liabilities;      

// }               cashflow; 

// #include <stdio.h>
// int main()
// {
//     cashflow munaCashflow;

//     munaCashflow.name = "muna";
//     munaCashflow.income = 2222;
//     munaCashflow.expenses = 600;
//     munaCashflow.assets = "business";
//     munaCashflow.liabilities = "food";

//     printf("Name: %s\n Income: %d\n Expeses: %d\n Assets: %s\n liabilities: %s\n", munaCashflow.name, munaCashflow.income, munaCashflow.expenses, munaCashflow.assets, munaCashflow.liabilities);
    
//     cashflow tahacashflow;

//     tahacashflow.name = "taha";
//     printf(" Name: %s\n", tahacashflow.name);
//     int x = 4;
//     int *y = &x;

//     printf("%p\n", y);
//     printf("%p\n", &x);
// }

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef struct list
// {
//     int data;
//     void *next;
// }               node;

// void *newNode(int content)
// {
//     node *newnode = malloc(sizeof(node));
//     if (!newnode)
//         return NULL;
    
//     newnode -> data = content;
//     newnode -> next = NULL;
// }
// int arrlen(size_t size)
// {
//     int i = 0;
//     while (i < size)
//         i++;
//     return i;
// }
// void printlist(node *head)
// {
//     while(head != NULL)
//     {
//         printf("%d\n", head -> data);
//         head = head->next;
//     }
// }
// node *arrtolist(int *arr, size_t size)
// {
//     int i = 1;
//     node *head = newNode(arr[0]);
//     node *mover = head;
//     while (i < arrlen(size))
//     {
//         node *tmp = newNode(arr[i]);
//         mover -> next = tmp;
//         mover = tmp;
//         i++;
//     }
//         return head;
// }

// int main()
// {
//     int arr[3] = {1 , 2 , 3};
//     size_t size = sizeof(arr) / sizeof(arr[0]);
//     node *head = arrtolist(arr, size);
//     printlist(head);
//     node *tmp = head;
//     while (tmp != NULL)
//     {
//         tmp = head -> next;
//         free(head);
//         head = tmp;
//     }
// }

// // to convert array to linked list
// // first I need to find the size of the array
// // so I can know how long I will loop for
// // size = sizeof(arr) / sizeof(arr[0]);  
// // for example [1, 2 , 3] size of arr of int = 12 (4 * 3) and int = 4 so 12 / 4 = 3 = size of array

// // I will create a pointer head
// //  node -> data = arr[0];
// //  node -> next = null;

// // I will create another pointer mover which points at head. and will loop in the list

// // the next step will be creating a tmp node
// // node -> data = arr[1];
// // node -> next = Null;

// // mover is responsible to connect between each node
// // mover -> next = tmp;
// // and then mover will point at the tmp
// // mover = tmp;

// // create another tmp with tmp -> data = next value of array (arr[2])
// // repeat process again

// // i = 0                           
// // while (i < 4)  while (i <= 4)  
// //     i++;            i++;
// //  4                     5 


// // i = 5;              
// // while (i--)    while (--i)
// //     5               4

// // i = 5
// // while (i > 0)     while (i >= 0)
// //     i--;               i--;
// //      5                  6

// // i = 0       
// //  while (++i < 5)   while (i++ < 5) 
// //      4                 5

#include <stdlib.h>
#include <stdio.h>


typedef struct list
{

    int data;
    struct list *next;

}              Node;

Node* createNode(int content)
{
    Node *node = malloc(sizeof(Node));
    node -> data = content;
    node ->next = NULL;
    return node;
}
Node* add_front(Node** node,int value)
{
    Node* newnode = createNode(value);
    newnode -> next = *node;
    *node = newnode;
    return *node;
}

void* printlist(Node *list)
{
    Node *tmp = list;
    while (tmp != NULL)
    {
        printf("%d\n", tmp -> data);
        tmp = tmp -> next;
    } 
}

void* deletelast(Node *list)
{
    if (list == NULL || list -> next == NULL)
        NULL;
    Node *tmp = list;
    while (tmp ->next->next != NULL)
        tmp = tmp->next;
    free(tmp -> next);
    tmp -> next = NULL;
}
Node **deletelist(Node **list, int k)
{
    if (*list == NULL)
        return list;
    if (k == 1)
    {
        Node* tmp = *list;
        *list = (*list) -> next;
        free(tmp);
        return (list);
    }
    Node *tmp = *list;
    Node *prev = NULL;
    int count = 0;
    while(tmp != NULL)
    {
        count++;
        if (count == k)
        {
            prev -> next = prev ->next -> next;
            free(tmp);
            return (list);
        }
        prev = tmp;
        tmp = tmp ->next;
    }
}
Node* add_back(Node *list, int val)
{
    if (list == NULL)
        return createNode(val);
    Node* newnode = createNode(val);
    Node *tmp = list;
    while (tmp ->next != NULL)
        tmp = tmp ->next;
    tmp -> next = newnode;
    return newnode;
}
Node** add_node(Node **node ,int value, int k)
{
    Node *newnode = createNode(value);
    Node *tmp = *node;
    int count = 0;
    if (*node == NULL && k == 1)
        {
            *node = newnode;
            return node;
        }
    else if (*node == NULL && k != 1)
        return NULL;
    else if (k == 1)
     {
        newnode -> next = *node;
        *node = newnode;
        return node;
     }
    while (tmp != NULL)
    {
        count++;
        if (count + 1 == k)
        {
            newnode -> next = tmp -> next;
            tmp -> next = newnode;
            break;
        }
        tmp = tmp -> next;
    }
    return node;
}
int main()
{
    Node* list = createNode(5);
    add_front(&list, 4);
    add_front(&list, 3);
    add_front(&list, 2);
    add_front(&list, 1);
    add_back(list, 7);
    int k = 1;
    // deletelist(&list,k);
    add_node(&list, 6, 6);
    printlist(list);

    Node* tmp = list;
    while (tmp != NULL)
    {
        tmp = list -> next;
        free(list);
        list = tmp;
    }
}




























































// ur statement was why would u work for someone else = job
// in the case of the loaner...  (yes some people work for him)  

// but what I was talking about is
//                                             this money down is working for both of us I mean 
//                                                                  |
//                                                      potential for money working for u 
// monthly income = 10,000;         monthly expenses             invest or save        rent
//                                  (between 3000 to 3300)          3367                3333
// rent = 3000;                                                              

// 3367 saving only while learning and looking for assets to invest

// this month I spended 3100
// 3300 - 3000 = 300. 

// what will decide what cost of a liability (car, house.....)

// investing money (assets) 

// cashflow = 20,000 monthly  car = -20,000 (once) monthly -2000 

// my cashflow = 18,000.
// income = 60,000 expenses = 30,000
// cashflow = 30,000.
// cashflow = 30,000 maybe buy a house perhaps 


// (their purpose of the debt is to buy liabilities... the government consider assets = worst nightmare)

// there is two human emotions that play a very big role in this equation...

// passion and fear...

// I believe fear is important but passion should win and be more

// black hole is fear... learning and building stuff is passion (just an example)

// getting a very huge income and a normal one doesnt matter if u cant manage them

// cashflow at the end is negative...






// this cashflow 30,000 caused me to get (1,000,000) why would I spend it.....
                                    
// take a loan for 1,400,000  pay monthly ummm  ur expenses 30,000 - 23,333
                                            
//               120,000 - 53,333 = 67000 per month
// pay each month 
// eventually negatives... (more positives).. 

// formula = to become richer 

// I will keep in mind to build things of course that benifit me and the world around
 
//  also  charity because I am free financally = I can afford charity and help people as possible
// time to search for more assets lets go....
// do dreams... businesses... work... and also enjoy life...
// now I am sure my kids and me, all family living peacefully with good finance

// cash
// depend on this number I might think about a car.


// 5 percent rich  15 percent(middle)  80 percent poor

// one of the reasons is the mindset



// for me the rich... is the money mindset.. it was the cashflow says about u 

// but u can be broke right now... but still rich so I am rich....

// being poor would never lead u to rich but broke might... 


// in my definition car not an asset... 

// the asset is the one that will get me the car 

// the middle save for the car 

// I luv ur opinion... my way in seeing it is different...

// the middle spend around half of there day working and thinking about the rich asset probelems

// rich spend there time getting asests, manage money, and do what they enjoy



// rich spend most o

// ur suggestions maybe not do 100 percent... but i might do a good percentage of them
// I wont do all ur style but take a bit of ur style... combine it with mine

// I want u to help me to build my life future brain storming... lets brain storm it one time...

// when u are less stress.. lets sit one day... and help me build my future plan...

// everything... lets say career for now and achieve dreams
// yes but we can do it as a second season of the show
// Do u agree ? In a day, we try to plan it out all ?? with ur handwriting plzzzz

// I prefer paper a notebook actually




