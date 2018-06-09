#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dec.h"

#define size 20
int array[size] = { 50, 79, 43, 21, 60, 52, 33, 92, 80, 11, 5, 93, 25, 7, 9, 4, 1, 33, 52, 52 };

void create_tree ( Tree *tree, int *array ) {
  int i = 0;
  while ( i < size ) {
      add_new_node ( tree, array[i] );
      i++;
  }
}


void test_of_inorder_traversal() {
  Tree tree;
  tree.root = NULL;
  create_tree ( &tree, array );
  printf ( "\nTWOJE DRZEWO:\n" );
  inorder_traversal ( &tree );
  delete_tree ( &tree );
}


void test_of_delete_node(){
  Tree tree;
  tree.root = NULL;
  create_tree ( &tree, array );

  delete_node ( &tree, 50 );
  delete_node ( &tree, 60 );
  delete_node ( &tree, 7 );
  delete_node ( &tree, 1 );
  delete_node ( &tree, 52 );
  delete_node ( &tree, 5 );
  delete_node ( &tree, 52 );
  delete_node ( &tree, 52 );
  delete_node ( &tree, 52 );
  delete_node ( &tree, 79 );
  delete_node ( &tree, 92 );
  delete_node ( &tree, 80 );
  delete_node ( &tree, 93 );
  delete_node ( &tree, 12 );
  delete_node ( &tree, 43 );

  printf ( "\nTWOJE DRZEWO:\n" );
  inorder_traversal ( &tree );
  delete_tree ( &tree );
}


void test_of_seek_node(){
  Tree tree;
  tree.root = NULL;
  struct node *temp = NULL;
  create_tree ( &tree, array );

  temp = seek_node ( &tree, 40 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 11 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 52 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 60 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 93 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 80 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 5 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 20 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 7 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 1 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 33 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 27 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 50 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 43 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 21 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 4 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 79 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 92 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 3 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 9 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 25 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 100 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, -1 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 0 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, -10 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, -3 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 0 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, 25 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 92 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 92 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, 92 );
  assert ( temp != NULL );
  temp = seek_node ( &tree, -1 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, -1 );
  assert ( temp == NULL );
  temp = seek_node ( &tree, -1 );
  assert ( temp == NULL );

  delete_tree ( &tree );
}



int main(){
  printf ( "\nTEST_OF_FUNCTION_INORDER_TRAVERSAL\n\n" );
  test_of_inorder_traversal();
  printf ("..............................................................................\n");
  printf ( "\nTEST_OF_FUNCTION_DELETE_NODE\n\n" );
  test_of_delete_node();
  printf ("..............................................................................\n");
  printf ( "\nTEST_OF_FUNCTION_SEEK_NODE\n\n" );
  test_of_seek_node();
  printf ("..............................................................................\n");

  return 0;
}
