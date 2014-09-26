#include "mylist.h"

/* empty_list.c
pre: takes a t_node** head pointing to a pointer pointing to the head of a list
post: removes every node in the list
*/
void empty_list(t_node** head){
  if(head)
    for(; *head; )
      remove_node(head);
}
