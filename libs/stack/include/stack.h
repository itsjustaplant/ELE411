//
// Created by Alperen on 24.09.2020.
//

#ifndef STACK_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_STACK_H
#define STACK_SIZE 10
struct Stack{
    int index;  //index of last element
    int* buffer; //The actual stack
};
/**
 * @brief   Constructor function for stack
 * @return  Stack pointer to the created Stack
 */
struct Stack* BuildStack();

/**
 * @brief   Destructor function for stack
 * @param stack
 */
void DestroyStack(struct Stack* stack);
 /**
  * @brief          Checks stack whether it is full or not
  * @param          stack
  * @return         int  1 if stack is full, 0 if not
  */
int isStackFull(struct Stack* stack);

/**
 * @brief           Checks stack whether it is empty or not
 * @param           stack
 * @return          int 1 if stack empty, 0 if not
 */
int isStackEmpty(struct Stack* stack);

/**
 * @brief       Adds item to stack
 * @param       block of data that will be added
 * @param       stack
 */
void Push(int block, struct Stack* stack);

/**
 * @brief       Deletes item from stack
 * @param       stack
 * @return
 */
void Pop(struct Stack* stack);
#endif //STACK_STACK_H
