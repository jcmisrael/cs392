#include "mylist.h"

/* traverse_string.
pre: takes a t_node*
post: posts every string contained within the nodes in the linked list pointed to by the t_node*
*/
void traverse_string(t_node* node){
  if(node){
    my_str((node->elem) ? (char*)node->elem : "NULL");
    node = node->next;
    for(; node; node = node->next){
      my_char(' ');
      my_str((node->elem) ? (char*)node->elem : "NULL");
    }
  }
}
