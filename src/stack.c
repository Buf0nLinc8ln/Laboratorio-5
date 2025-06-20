#include <stdio.h>

#include "../include/stack.h"

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: No se pueden agregar más elementos.\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: La pila está vacía.\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void printStack(Stack *s) {
    printf("Contenido de la pila: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
