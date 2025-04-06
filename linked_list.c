#include "linked_list.h"
#include <stdlib.h>

struct list_node *new_node(size_t value) {
  struct list_node * node = (struct list_node*) malloc(sizeof(struct list_node));
  if (!node)
  {
    return NULL;
  }
  node -> value = value;
  node -> next = NULL;
  return node; 
  }

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node *node = new_node(value);
  if (!node)
  {
    return;
  }
  node -> next = list -> head;
  list -> head = node;

}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node *node = new_node(value);
  if (!node)
  {
    return;
  }
  if(list -> head == NULL)
  {
    list -> head = node;
  }
  return;
  
}

size_t remove_from_head(struct linked_list *list) { 
  if (list -> head == NULL) //check if list is empty
  {
    return 0;
  }
  struct list_node *yoink = list -> head;
  list-> head = list -> head -> next;
  free(yoink);
  return 0; 
  }
  
size_t remove_from_tail(struct linked_list *list) { 
  
  if (list -> head == NULL) 
  {
    return 0;
  }

  if (list->head->next == NULL) //last node in list
  {
   free(list -> head);  //free only node in list
   list -> head = NULL; //empty list
   return; 

  }
  struct list_node * current = list-> head; // Multiple nodes - find the second-to-last node
  while (current->next->next != NULL) 
  {
      current = current->next;
  }

    size_t value = current->next->value;
    free(current->next);
    current->next = NULL; // current is the last node
    return value;
    
  return 0;
}

void free_list(struct linked_list list) {
  struct list_node *current = list.head
  while (current != NULL)
  {
    struct list_node *next = current -> next;
    free(current);
    current = next;
  }

}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
