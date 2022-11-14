#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
    if (p == NULL)
    return;
  else // printer næste værdi i listen
  {
    printf("%d ", p->value);
    print_list(p->next);
  }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
 if (p == NULL) /*base case*/
    return 0; // hvis der ikke er noget man kan finde summen af
  else
    return p->value * p->value + sum_squares(p->next);
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
    node *temp = malloc(sizeof(node));
  if (p == NULL) {
    return NULL; //returns NULL, as the new list also needs a null pointer in the end. 
  }
  else {
    temp->value = f(p->value); //make temps value p->value squared
    temp->next = map(p->next,f); //make connection, and send p and function
    return temp; //return pointer for every function call
  }
  
  return NULL; 
}

int square(int x)
{
  return x * x;
}

 