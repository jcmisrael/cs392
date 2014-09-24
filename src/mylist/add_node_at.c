#include "mylist.h"

/* add_node_at.c
pre: takes a t_node* n, t_node** head, and unsigned int i
post: adds to the node to the list at position i from head
*/
void add_node_at(t_node* n, t_node** head, unsigned int i){
  if(n && head){
    if(!(*head))
      *head = n;
    else {
      if(i == 0)
	add_node(n, head);
      else {
	for(; (*head)->next && i > 1; head = &((*head)->next), --i)
	  ;
	n->next = (*head)->next;
	(*head)->next = n;
      }
    }
  }
}
