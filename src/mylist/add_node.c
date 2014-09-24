#include "mylist.h"

/* add_node.c
pre: takes a t_node* and a t_node** pointing to the pointer to the head of a list
post: points the head node to the t_node passed and points that to the previous head
*/
void add_node(t_node* n, t_node** head){
  if(head && n){
    n->next = *head;
    *head = n;
  }
}
