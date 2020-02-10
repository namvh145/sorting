#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
    node* next;
} node;
node *z = NULL;
node *merge(node *a, node *b)
{
    node *c;
    c = z;
    do
    {
        if (a->key > b->key)
        {
            c->next = a;
            c = a;
            a = a->next;
        }
        else
        {
            c->next = b;
            c = b;
            b = b->next;
        }
    } while (c != z);
    c = z->next;
    z->next = z;
    return c;
}
node *mergesort(node *c) {
    node *a;
    node *b;
    /* test if list has at least 2 elements */
    if (c != z && c->next != z) {
        /* locate the middle node */
        a = b = c;
        while (b->next != z && b->next->next != z) {
            c = c->next;
            b = b->next->next;
        }
        /* split the list between c and c->next */
        b = c->next;
        c->next = z;
        /* sort both sublists and merge them */
        return merge(mergesort(a), mergesort(b));
    }
    return c;
}
void printList(node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->key); 
        node = node->next; 
    } 
} 
/* Function to insert a node at the beginging of the linked list */
void push(node** head_ref, int new_data) 
{ 
    /* allocate node */
    node* new_node = (node*)malloc(sizeof(node)); 
    /* put in the data */
    new_node->key = new_data; 
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
int main() 
{ 
    /* Start with the empty list */
    node* res = NULL; 
    node* a = NULL; 
    /* Let us create a unsorted linked lists to test the functions 
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
    mergesort(&a); 
    printf("Sorted Linked List is: \n"); 
    printList(a); 
  
    getchar(); 
    return 0; 
} 
