//
// Created by Alperen on 24.09.2020.
//

#include "stack.h"

struct Stack* BuildStack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> buffer = (int*) malloc(sizeof(int) * STACK_SIZE);
    stack -> index  = 0;
    return stack;
}

int isStackFull(struct Stack* stack){
    int r_value = 0;
    if(stack -> index == STACK_SIZE){
        r_value = 0;
    } else{
        r_value = 1;
    }
    return r_value;
}
int isStackEmpty(struct Stack* stack){
    int r_value = 0;
    if (stack -> index == 0){
        r_value = 1;
    } else{
        r_value = 0;
    }
    return r_value;
}
void Push(int block, struct Stack* stack){
    int* s_index = &(stack -> index);
    if (isStackFull(stack)){
        stack -> buffer[*s_index] = block;
        *s_index += 1;
    } else{
        printf("stack is full\n");
    }

}
void Pop(struct Stack* stack){

    int* s_index = &(stack -> index);
    if (isStackEmpty(stack)){
        printf("Stack is empty\n");
    } else{
        int* block = &(stack -> buffer[*s_index-1]);
        printf("%d\n",*block);
        *s_index -= 1;
    }
}
