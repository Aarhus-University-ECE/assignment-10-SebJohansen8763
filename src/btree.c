#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) { //indsætter node ind i træet t
{
  if (t == NULL) { //hvis t er tomt
    struct tree_node *new_node = malloc(sizeof(struct tree_node)); //allokere plads til ny node
    new_node->item = x; //ny nodes værdi sættes til x
    new_node->left = NULL; //ny nodes venstre barn sættes til NULL
    new_node->right = NULL; //ny nodes højre barn sættes til NULL
    t = new_node; //t sættes til ny node
  }
  else if (t->item >= x) //hvis t's værdi er større eller lig med x
  {
    t->right = Insert(x, t->right); //indsætter x i t's højre barn
  }
  else if (t->item < x) //hvis t's værdi er mindre end x
  {
    t->left = Insert(x, t->left); //indsætter x i t's venstre barn
  }
  return t;
}
}

struct tree_node *Remove(int x, struct tree_node *t){
{
  if (t == NULL){ // hvis t er lig NULL
  }
  else if (t->item > x) //hvis t's værdi er større end x
    t->right = Remove(x, t->right); //fjerner x fra t's højre barn
  else if (t->item < x) // hvis t's værdi er mindre end x
    t->left = Remove(x, t->left); // fjerner x fra t's venstre barn
  else if (t->item == x) // hvis t's værdi er lig x
  {
    struct tree_node *temp = t; //temp sættes til t
    if (t->left == NULL) //hvis t's venstre barn er lig NULL
      t = t->right; //t sættes til t's højre barn

    else if (t->left->right == NULL) //hvis t's venstre barns højre barn er lig NULL
    {
      t->left->right = t->right; //t's venstre barns højre barn sættes til t's højre barn
      t = t->left; //t sættes til t's venstre barn
    }

    /* case 3: left node is not the biggest of the smallest */
    else if (t->left->right != NULL) // hvis t's venstre barns højre barn ikke er lig null
    {
      temp = t->left->right; //temp sættes til t's venstre barns højre barn
      while (temp->right != NULL) //så længe temp's højre barn ikke er lig NULL
        temp = temp->right; //temp sættes til temp's højre barn
      t->item = temp->item; //t's værdi sættes til temp's værdi
    }

    free(temp); //frigører temp
  }
  return t;
}
  return NULL;
}

int Contains(int x, struct tree_node *t){ // tjekker om x er i træet t
  if (t == NULL)
  {
    return 0;
  }
  else if (t->item > x) // hvis t's værdi er større end x
  {
    return Contains(x, t->right);
  }
  else if (t->item < x) // hvis t's værdi er mindre end x
  {
    return Contains(x, t->left);
  }
  else if (t->item == x) // hvis t's værdi er lig x
  {
    return 1;
  }
  return 0;
}
struct tree_node *Initialize(struct tree_node *t){ // initialiserer træet t
  t = NULL; //t sættes til NULL
  return t;
}

int Empty(struct tree_node *t){ // tjekker om træet t er tomt
  return t == NULL;
}

int Full(struct tree_node *t) { // tjekker om træet t er fuldt
  return 0;
}
