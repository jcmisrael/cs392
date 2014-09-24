#include "mylist.h"

/* count_nodes.c
pre: takes a t_node* head pointer to the head of a list
post: returns an int i equal to the number of nodes found in the list
*/
unsigned int count_nodes(t_node* head){
  unsigned int c = 0;
  if(head)
    for(; head; head = head->next)
      ++c;
  return c;
}
