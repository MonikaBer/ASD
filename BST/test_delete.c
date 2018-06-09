#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dec.h"

#define quantity_of_nodes 400

void create_tree ( Tree *tree ) {
  int i = 0, value;
  srand ( time (NULL) );
  printf ( "\n\nDODAWANE ELEMENTY:\n" );
  while ( i < quantity_of_nodes ) {
      value = rand() % 250 + 1;
      printf ( "%d\n", value );
      add_new_node ( tree, value );
      i++;
  }
}


void test() {
  Tree tree;
  tree.root = NULL;
  create_tree ( &tree );
  printf ( "\nTWOJE DRZEWO:\n" );
  inorder_traversal ( &tree );

  printf ( "\n\nUSUWANE ELEMENTY:\n" );
  int value, i = 0;
  while ( i < 300 ) {
      value = rand() % 250 + 1;
      printf ( "%d\n", value );
      delete_node ( &tree, value );
      i++;
  }

  printf ( "\n\nTWOJE DRZEWO:\n" );
  inorder_traversal ( &tree );
  delete_tree ( &tree );
}


int main(){
  printf ( "\nTEST_OF_FUNCTION_DELETE_NODE\n\n" );
  test();

  return 0;
}
