#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

struct node* create_new_node (struct node*, int);
struct node* left_subtree_max ( struct node* );  //zwraca wskaznik na max element w lewym poddrzewie
struct node* right_subtree_min ( struct node* );  //zwraca wskaznik na min element w prawym poddrzewie
struct node* find_son ( struct node* );
void swap ( struct node*, struct node* );  //zamienia klucze dwoch wezlow
void delete_node_helper ( struct node*, struct node*, int );
void delete_node_without_sons ( struct node**, struct node* );
void delete_node_with_one_son ( struct node* );
void delete_node_with_two_sons ( struct node*, struct node*, int );


struct node* create_new_node ( struct node *new_node, int value ){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> x = value;
    new_node -> left_son = NULL;
    new_node -> right_son = NULL;
    new_node -> parent = NULL;
    return new_node;
}


struct node* left_subtree_max ( struct node *temp ) {
  struct node *extreme_node = temp -> left_son;
  while ( extreme_node -> right_son != NULL )  extreme_node = extreme_node -> right_son;
  return extreme_node;
}


struct node* right_subtree_min ( struct node *temp ) {
  struct node *extreme_node = temp -> right_son;
  while ( extreme_node -> left_son != NULL )  extreme_node = extreme_node -> left_son;
  return extreme_node;
}


struct node* find_son ( struct node *temp ) {
  return temp->left_son == NULL ? temp -> right_son : temp -> left_son;
}


void swap ( struct node *temp, struct node *extreme_node ) {
  int helper_to_swap = temp -> x;
  temp -> x = extreme_node -> x;
  extreme_node -> x = helper_to_swap;
}


void delete_node_without_sons ( struct node **root, struct node *temp ){  //*temp to wskaznik na usuwany element
  if ( temp == *root )  *root = NULL;
  else {
      if ( temp == temp->parent->left_son )  temp->parent->left_son = NULL;
      else  temp->parent->right_son = NULL;
  }
  free (temp);
}


void delete_node_with_one_son (  struct node *temp ){  //*temp to wskaznik na usuwany element
  struct node *son = find_son ( temp );  //zwraca wskaznik *son na jedynego syna rodzica na ktorego wskazuje *temp
  temp -> x = son -> x;
  temp -> left_son = son -> left_son;
  temp -> right_son = son -> right_son;
  if ( son->left_son != NULL )  son->left_son->parent = temp;
  if ( son->right_son != NULL )  son->right_son->parent = temp;
  free (son);
}


void delete_node_helper ( struct node *root, struct node *extreme_node, int value ){  //usuwa element majac dany wskaznik *extreme_node na element do usuniecia
    struct node *temp = extreme_node;
    if ( temp == NULL )  printf ( "ELEMENT %d NIE WYSTEPUJE W DRZEWIE!\n", value );
    else {
        if ( temp->left_son == NULL && temp->right_son == NULL )
            delete_node_without_sons ( &root, temp );
        else if ( temp->left_son != NULL && temp->right_son != NULL )
            delete_node_with_two_sons ( root, temp, value );
        else
            delete_node_with_one_son ( temp );
    }
}


void delete_node_with_two_sons ( struct node *root, struct node *temp, int value ){  //*temp to wskaznik na usuwany element
  struct node *extreme_node = left_subtree_max ( temp );
  swap ( temp, extreme_node );
  delete_node_helper ( root, extreme_node, value );
}


 void add_new_node ( Tree *tree, int value ){
    struct node *new_node = NULL;
    new_node = create_new_node ( new_node, value );
    if ( tree->root == NULL )  tree -> root = new_node;
    else {
        struct node *temp = tree -> root;
        while ( temp != NULL ){
            if ( new_node->x < temp->x ) {
                if ( temp->left_son == NULL ){
                    new_node -> parent = temp;
                    temp -> left_son = new_node;
                    temp = NULL;
                }
                else  temp = temp -> left_son;
            }
            else if ( new_node->x > temp->x ) {
                if ( temp->right_son == NULL ){
                    new_node -> parent = temp;
                    temp -> right_son = new_node;
                    temp = NULL;
                }
                else  temp = temp -> right_son;
            }
            else {
                printf ( "ELEMENT O TAKIM KLUCZU JUZ BYL W DRZEWIE!\n" );
                temp = NULL;
                free (new_node);
            }
        }
    }
}


void print_node ( struct node *node ) {
  printf ( "%d\n", node -> x );
}


void _inorder_traversal ( struct node *node, void (*f)(struct node*) ){
  if ( node == NULL )  return;
  _inorder_traversal ( node -> left_son, f );
  (*f)(node);
  _inorder_traversal ( node -> right_son, f );
}


void inorder_traversal ( Tree * tree ) {
  _inorder_traversal( tree -> root, &print_node );
}


struct node* seek_node ( Tree *tree, int value ){  //zwraca wskaznik na szukany element lub NULL gdy element nie wystepuje
    struct node *temp = tree -> root;
    while ( temp != NULL ){
        if ( value < temp->x )       temp = temp -> left_son;
        else if ( value > temp->x )  temp = temp -> right_son;
        else                         return temp;
    }
    return temp;
}


void delete_node ( Tree *tree, int value ){
    delete_node_helper ( tree->root, seek_node ( tree, value ), value );
}


void _delete_tree ( struct node* root ) {
  if ( root == NULL )  return;
  _delete_tree ( root -> left_son );
  _delete_tree ( root -> right_son );
  free ( root );
}


void delete_tree ( Tree *tree ) {
  _delete_tree ( tree -> root );
}
