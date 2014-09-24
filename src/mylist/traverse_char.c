#include "mylist.h"

/* traverse_char.c
pre: takes a t_node*
post: posts every char contained within the nodes in the linked list pointed to by the t_node*
*/
void traverse_char(t_node* node){
  if(node){
    if(node->elem)
      my_char(*((char*)node->elem));
    else
      my_str("NULL");
    node = node->next;
    for(; node; node = node->next){
      my_char(' ');
      if(node->elem)
	my_char(*((char*)node->elem));
      else
	my_str("NULL");
    }
  }
}
