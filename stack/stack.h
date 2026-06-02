#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

#define MAX 100

struct Stack{
    int currentPointer;
    int data[MAX];
};  


Stack createStack(){
    Stack stack;
    stack.currentPointer=0;
    return stack;
}

void push(Stack* stack,int data){
    if(stack->currentPointer==MAX){
        printf("Stack overflow");
        return;
    }

    stack->data[stack->currentPointer++]=data;
    return;
}

int pop(Stack* stack,int data){
    if(stack->currentPointer==0){
        printf("Stack underflow");
        return;
    }

    return stack->data[--stack->currentPointer];
}

bool isEmpty(Stack* stack){
    if(stack->currentPointer==0) return true;
    return false;
}

bool isFull(Stack* stack){
    if(stack->currentPointer==MAX) return true;
    return false;
}

