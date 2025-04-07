#include "queue.h"
#include "tile_game.h"

static struct list_node *new_node(struct game_state state) {
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    if (!node) {
        return NULL; // Return NULL if allocation fails
    }
    node->value = (size_t)malloc(sizeof(struct game_state));  // Assuming you want to store the address of state
    if (!node-> value){
        free(node);
        return NULL;
    }
    *(struct game_state *)node->value = state;  // Copy state into the node
    node->next = NULL;
    return node;
}

void enqueue(struct queue *q, struct game_state state) {
    struct list_node *node = new_node(state);
    if (!node) {
        return; // Allocation failed
    }

    // Insert at the tail of the linked list
    if (q->data.head == NULL) {
        q->data.head = node;
    } else {
        struct list_node *current = q->data.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}


struct game_state dequeue(struct queue *q) { 
    if(q->data.head == NULL )
    {
        exit(1);
    }

    struct list_node *node = q->data.head;
    struct game_state *state = (struct game_state *)node->value;

    q->data.head = node->next;
    free(node);

    return *state;
}

void free_queue(struct queue *q) {
    struct list_node *current = q->data.head;
    while (current != NULL) {
        struct list_node *next_node = current->next;
        free(current);
        current = next_node;
    }
    q->data.head = NULL; 
}

int number_of_moves(struct game_state start) { 
    return start.num_steps;
}
