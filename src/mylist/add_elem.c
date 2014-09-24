#include "mylist.h"

/* add_elem.c
pre: takes a void* and a t_node** pointing to the pointer to the head of a list
post: creates a new node containing the passed void*, and points the head to that, and pointing that to the old head
*/
void add_elem(void* e, t_node** head){
  if(head && e){
    t_node* n = new_node(e, *head);
    *head = n;
  }
}
