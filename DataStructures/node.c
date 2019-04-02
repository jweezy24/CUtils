#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* left;
  struct node* right;
  char* val;
}node;

node* init_node(node* newNode){
  new = malloc(sizeof(node));
  new->left = malloc(sizeof(node));
  new->right = malloc(sizeof(node));
  new->val = malloc(sizeof(char));
  return newNode;
}

void create_null_node(node* nullVal){
  nullVal = malloc(sizeof(node));
  nullVal->left = malloc(sizeof(node));
  nullVal->right = malloc(sizeof(node));
  strcpy(tempNode->val, "NONE");

}

void copyNewNode(node* old, node* new){
}

void setNodeL(node* parent, node* child){
  parent->left = child;
}

void setNodeR(node* parent, node* child){
  parent->right = child;
}
