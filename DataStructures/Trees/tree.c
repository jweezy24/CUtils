#include <stdio.h>
#include <stdlib.h>
#include "../node.c"


typedef struct tree{
  node* root;
  int size;
}tree;



void init_tree(*tree data){
  data = malloc(sizeof(tree));
  tree->root = malloc(sizeof(node));
  tree->root->right = malloc(sizeof(node));
  tree->root->left = malloc(sizeof(node));
  tree->root->val = malloc(sizeof(char));
}

void add_node(tree* data, node* newNode){

}
