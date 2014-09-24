#include "mylist.h"

/* append.c
pre: takes a t_node* and a t_node** pointing to the pointer to a the head of a list
post: appends the t_node* to the end of the list pointed to by the t_node**
*/
void append(t_node* n, t_node** head){
  if(n && head){
    if(!(*head))
      *head = n;
    else {
      for(; (*head)->next; head = &((*head)->next))
	    ;
      (*head)->next = n;
    }
  }
}
