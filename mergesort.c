#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node;
typedef struct node_t { int key; node *next; } node;
node *z = NULL;
node *merge(node *a, node *b)
{
    node *c = z;
    do
    {
        if (a->key > b->key)
        {
            c->next = a; c = a; a = a->next;
        }
        else
        {
            c->next = b; c = b; b = b->next;
        }
    } while (c != z);
    c = z->next;
    z->next = z;
    return c;
}
node *mergesort(node *c) {
    node *a = z; 
    node *b = z;
    if (c != z && c->next != z) {
        a = b = c;
        while (b->next != z && b->next->next != z) {
            c = c->next;
            b = b->next->next;
        }
        b = c->next;
        c->next = z;
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
void push(node** head_ref, int new_data) 
{ 
    node* new_node = (node*)malloc(sizeof(node)); 
    new_node->key = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
int main() 
{ 
    node* res = NULL; 
    node* a = NULL;
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
    a = mergesort(a); 
    printf("Sorted Linked List is: \n"); 
    printList(a); 
  
    getchar(); 
    return 0; 
} 
