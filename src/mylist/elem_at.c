#include "mylist.h"

/* elem_at.c
pre: takes a t_node* head pointing to the head of a list and an unsigned int i
post: returns the element contained within the node at index i within the list
*/
void* elem_at(t_node* head, unsigned int i){
  if(head)
    for(; head->next && i > 0; head = head->next, --i)
      ;
  else
    return NULL;
  return head->elem;
}
