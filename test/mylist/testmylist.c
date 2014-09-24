#ifndef NL
#define NL my_char('\n');
#endif

#include "mylist.h"

int main(int argc, char* args[]){
  t_node* head = NULL;
  t_node* t1 = NULL;
  t_node* t2 = NULL;
  t_node* intlist = NULL;
  t_node* charlist = NULL;
  char* s1;
  char* c1 = xmalloc(sizeof(char));
  char* c2 = xmalloc(sizeof(char));
  int* i1 = xmalloc(sizeof(int));
  int* i2 = xmalloc(sizeof(int));
  *c1 = 'a';
  *c2 = 'b';
  *i1 = 5;
  *i2 = 10;

  // Testing new_node
  my_str("Testing new_node.\n");
  head = new_node(NULL, NULL);
  my_str((head) ? "!NULL\n" : "NULL\n"); /* Print: !NULL */
  head = new_node(my_strdup("Node1"), NULL);
  my_str((head) ? "!NULL\n" : "NULL\n"); /* Print: !NULL */
  my_str((char*) head->elem);		 /* Print: Node1 */
  NL
  NL

  /* Testing add_node */
  my_str("Testing add_node.\n");
  add_node(NULL, &head);
  my_str(head->elem);		/* Prints: Node1 */
  NL
  t1 = new_node(my_strdup("Node2"), NULL);
  add_node(head, NULL); 	/* No clue how to test for this */
  add_node(t1, &head);
  my_str(head->elem);		/* Prints: Node2 */
  NL
  my_str(head->next->elem);	/* Prints: Node1 */
  NL
  NL

  /* Testing add_elem */
  my_str("Testing add_elem.\n");
  add_elem(NULL, &head);
  my_str(head->elem);		/* Prints: Node2 */
  NL
  s1 = my_strdup("Node3");
  add_elem(s1, NULL);		/* Hopefully doesnt crash */
  add_elem(NULL, NULL);		/* Hopefully doesnt crash */
  add_elem(s1, &head);
  my_str(head->elem);		/* Prints: Node3 */
  NL
  NL

    /* Testing traverse_string */
    my_str("Testing traverse_string.\n");
  traverse_string(head);	/* Prints: Node3 Node2 Node1 */
  NL
  traverse_string(NULL);	/* Prints: nothing */
  NL

  /* Testing traverse_int */
  my_str("Testing traverse_int.\n");
  add_elem(i1, &intlist);
  add_elem(i2, &intlist);
  traverse_int(intlist);	/* Prints: 10 5 */
  NL
  traverse_int(NULL);		/* Prints: Nothing */
  NL

    /* Testing traverse_char */
    my_str("Testing traverse_char.\n");
  add_elem(c1, &charlist);
  add_elem(c2, &charlist);
  traverse_char(charlist);	/* Prints: b a */
  NL
  traverse_char(NULL);		/* Prints: nothing */
  NL

  /* Testing append */
  my_str("Testing append.\n");
  append(new_node(my_strdup("Node4"), NULL), &head);
  traverse_string(head);	/* Prints: Node3 Node2 Node1 Node4 */
  NL
  append(NULL, &head);
  traverse_string(head);	/* Prints: Node3 Node2 Node1 Node4 */
  NL
  append(head, NULL);		/* Hopefully doesn't crash */
  append(NULL, NULL);		/* Doesn't Crash */
  NL

  /* Testing add_node_at */
  my_str("Testing add_node_at.\n");
  add_node_at(NULL, &head, 0);
  traverse_string(head);	/* Prints: Node3 Node2 Node1 Node4 */
  NL
  add_node_at(head, NULL, 5);	/* Doesn't crash */
  add_node_at(new_node(my_strdup("Node5"), NULL), &head, 1);
  traverse_string(head);	/* Prints: Node3 Node5 Node2 Node1 Node4 */
  NL
  add_node_at(NULL, NULL, 2);	/* Doesnt crash */
  NL

  /* Testing remove_node */
  my_str("Testing remove_node.\n");
  my_str(remove_node(&head));	/* Prints: Node3 */
  NL
  traverse_string(head);	/* Prints: Node5 Node2 Node1 Node4 */
  NL
  my_str(remove_node(NULL));	/* Prints: nothing */
  NL
  t1 = NULL;
  my_str(remove_node(&t1));	/* Prints: nothing */
  NL

  /* Testing remove_node_at */
  my_str("Testing remove_node_at.\n");
  my_str(remove_node_at(&head, 1)); /* Prints: Node2 */
  NL
  traverse_string(head);	    /* Prints: Node5 Node1 Node4 */
  NL
  my_str(remove_node_at(NULL, 1));  /* Prints: nothing */
  NL

  /* Testing remove_last */
  my_str("Testing remove_last.\n");
  my_str(remove_last(&head));	/* Prints: Node4 */
  NL
  traverse_string(head);	/* Prints: Node5 Node1 */
  NL
  my_str(remove_last(NULL));	/* Prints: nothing */
  NL

    /* Testing count_nodes */
    my_str("Testing count_nodes.\n");
  my_int(count_nodes(head));	/* Prints: 2 */
  NL
  my_int(count_nodes(NULL));	/* Prints: 0 */
  NL
  NL

    /* Testing node_at */
  my_str("Testing node_at.\n");
  my_str(node_at(head, 0)->elem); /* Prints: Node5 */
  NL
  my_str((node_at(NULL,5)) ? "!NULL" : "NULL"); /* Prints: NULL */
  NL
  NL

    /* Testing elem_at */
    my_str("Testing elem_at.\n");
  my_str(elem_at(head, 10));	/* Prints: Node1 */
  NL
  my_str((elem_at(NULL, 1)) ? "!NULL" : "NULL"); /* Prints: NULL */
  NL
  NL

    /* Testing empty_list */
    my_str("Testing empty_list.\n");
  my_str((head) ? "!NULL" : "NULL"); /* Prints: !NULL */
  NL
  empty_list(&head);
  my_str((head) ? "!NULL" : "NULL"); /* Prints: NULL */
  NL
  empty_list(NULL);		/* Shouldnt Crash */

}
