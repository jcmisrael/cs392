#include "mylist.h"

/* node_at.c
pre: takes a t_node* pointing to the head of a list and an unsigned int i
post: returns a pointer to the node at index i in the list
*/
t_node* node_at(t_node* head, unsigned int i){
  if(head)
    for(; head->next && i > 0; head = head->next, --i)
      ;
  return head;
}
