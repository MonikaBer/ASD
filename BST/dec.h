#ifndef DEC_H
#define DEC_H

struct node {
    int x;
    struct node* left_son;
    struct node* right_son;
    struct node* parent;
};

struct tree {
  struct node* root;
};
typedef struct tree Tree;

void add_new_node ( Tree*, int );
void inorder_traversal ( Tree* );
struct node* seek_node ( Tree*, int );  
void delete_node ( Tree*, int );
void delete_tree ( Tree* );

#endif
