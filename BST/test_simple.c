#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dec.h"

#define quantity_of_nodes 100

void create_tree ( Tree *tree ) {
  int i = 0, value;
  srand ( time (NULL) );
  while ( i < quantity_of_nodes ) {
      value = rand() % 100 + 1;
      add_new_node ( tree, value );
      i++;
  }
}


void test_simple() {
  Tree tree;
  tree.root = NULL;
  create_tree ( &tree );
  inorder_traversal ( &tree );
  delete_tree ( &tree );
}


int main(){
  printf ( "\nTEST_OF_FUNCTION_INORDER_TRAVERSAL\n\n" );
  test_simple();

  return 0;
}
