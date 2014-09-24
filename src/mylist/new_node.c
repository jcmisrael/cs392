#include "mylist.h"

/*  new_node.c
pre: takes an elem and a t_node*
post: returns a node*
*/
t_node* new_node(void* e, t_node* n){
  t_node* node = (t_node*) xmalloc(sizeof(t_node));
  node->elem = e;
  node->next = n;
  return node;
}
