#include "mylist.h"

/* remove_node_at.c
pre: takes a t_node** head and an unsigned int i
post: Removes the node at index i in list head, returning the elem within
*/
void* remove_node_at(t_node** head, unsigned int i){
  void* elem = NULL;
  t_node* n = NULL;
  if(head){
    if(*head){
      if(i == 0 || !((*head)->next))
	return remove_node(head);
      else {
	for(; (*head)->next->next && i > 1; head = &((*head)->next), --i)
	  ;
	n = (*head)->next;
	(*head)->next = n->next;
	elem = n->elem;
	n->next = NULL;
	free(n);
      }
    }
  }
  return elem;
}
