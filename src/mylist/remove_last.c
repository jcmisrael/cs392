#include "mylist.h"

/* remove_last.c
pre: takes a t_node** head pointing to the head of a list
post: Removes the last value in the list, returning the elem within
*/
void* remove_last(t_node** head){
  void* elem = NULL;
  if(head){
    if(*head){
      if(!((*head)->next))
	return remove_node(head);
      else {
	for(; (*head)->next->next; head = &((*head)->next))
	  ;
	elem = (*head)->next->elem;
	(*head)->next->next = NULL;
	free((*head)->next);
	(*head)->next = NULL;
      }
    }
  }
  return elem;
}
