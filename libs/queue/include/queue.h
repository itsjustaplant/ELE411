//
// Created by Alperen on 24.09.2020.
//

#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H
#define QUEUE_SIZE 10
#include <stdlib.h>
#include <stdio.h>

struct Queue{
    int index;
    int* buffer;
};
/**
 * @brief     Constructor function for stack
 * @return    Queue pointer to the created queue
 */
struct Queue* BuildQueue();

/**
 * @brief     Destructor function for stack
 * @param queue
 */
void DestroyQueue(struct Queue* queue);

/**
 * @brief  Checks if queue is full
 * @param  queue
 * @return int 1 if queue full, 0 if not
 */
static int isFull   (struct Queue* queue);

/**
 * @brief  Checks if queue is empty
 * @param queue
 * @return int 1 if queue empty, 0 if not
 */
static int isQueueEmpty  (struct Queue* queue);

/**
 * @brief        Adds item to queue
 * @param block  Item will be added
 * @param queue
 */
void Enqueue (int block, struct Queue* queue);

/**
 * @brief         Deletes item from queue
 * @param queue
 */
void Dequeue (struct Queue* queue);
#endif //STACK_QUEUE_H
