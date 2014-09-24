#include "mylist.h"

/* empty_list.c
pre: takes a t_node** head pointing to a pointer pointing to the head of a list
post: removes every node in the list
*/
void empty_list(t_node** head){
  t_node* prev = NULL;
  t_node* next = NULL;
  if(head && *head){
    next = *head;
    prev = next;
    for( ; next; ){
      if(prev->elem)
	free(prev->elem);
      next = next->next;
      prev->next = NULL;
      free(prev);
      prev = next;
    }
    *head = NULL;
  }
}
