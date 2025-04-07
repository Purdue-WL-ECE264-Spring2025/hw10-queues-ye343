#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
    uint64_t value = serialize(state);
    insert_at_tail(&q-> data, value);
}


struct game_state dequeue(struct queue *q) { 
    uint64_t value = remove_from_head(&q -> data);
    return deserialize(value);
}

int number_of_moves(struct game_state start) { 
    struct queue q = {0};  // Initialize the queue
    enqueue(&q, start);    // Enqueue the starting state

    return -1;  // Return -1 if no solution is foundreturn 0; 
}
