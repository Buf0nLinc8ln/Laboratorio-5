#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;
    initialize(&s);
    printf("Añadiendo 5 y 10 en la pila...\n");
    push(&s, 5);
    push(&s, 10);
    printStack(&s);
    printf("Eliminando el último elemento de la pila...\n");
    int elim = pop(&s);
    printf("Elemento eliminado de la pila: %d\n", elim);
    printStack(&s);

    return 0;
}
