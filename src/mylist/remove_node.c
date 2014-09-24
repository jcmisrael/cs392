#include "mylist.h"

/* remove_node.c
pre: takes a t_node** pointing to the head of a list
post: Removes the first elem in the list, returning its value.
*/
void* remove_node(t_node** head){
  void* elem = NULL;
  t_node* next = NULL;
  if(head){
    if(*head){
      elem = (*head)->elem;
      next = (*head)->next;
      (*head)->next = NULL;
      free(*head);
      *head = next;
    }
  }
  return elem;
}
