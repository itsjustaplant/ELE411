//
// Created by Alperen on 24.09.2020.
//

#include "../include/queue.h"
struct Queue* BuildQueue(){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue -> buffer = (int*) malloc(sizeof(int) * QUEUE_SIZE);
    queue -> index = 0;
    return queue;
}

static int isQueueFull(struct Queue* queue){
    int r_value = 0;
    if (queue -> index == 10){
        r_value = 1;
    } else{
        r_value = 0;
    }
    return r_value;
}
static int isQueueEmpty(struct Queue* queue){
    int r_value = 0;
    if (queue -> index == 0){
        r_value = 1;
    } else{
        r_value = 0;
    }
    return r_value;
}
void Enqueue(int block, struct Queue* queue){
    int* q_index = &(queue -> index);
    if(isQueueFull(queue)){
        printf("Queue is full\n");
    } else{
        queue -> buffer[*q_index] = block;
        *q_index += 1;
    }
}
void Dequeue(struct Queue* queue){
    int* q_index = &(queue -> index);
    if (isQueueEmpty(queue)){
        printf("Queue is empty\n");
    } else{
        int* block = &(queue -> buffer[0]);
        printf("%d\n",*block);
        if (*q_index == 1){
            queue -> buffer[0] = queue -> buffer[1];
            queue -> buffer[1] = 0;
        } else{
            for (int i = 0; i < *q_index-1; ++i) {
                queue -> buffer[i] = queue -> buffer[i+1];
            }
        }
        *q_index -= 1;
    }
}