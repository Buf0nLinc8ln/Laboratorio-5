
// bibliotecas que usan

#include <stdio.h>

// Los .h de cada estructura

#include "../Laboratorio-5/include/ListasDoblementeEnlazadas.h"
#include "stack.h"

int main() {
    int opcion;

    while (1) {
        printf("\nMenú:\n");
        printf("[0. Salir|1. ListasDoblementeEnlazadas|2. Stack]:"); // agregar nombre de estructura, numerado
        printf("Ingrese una opción:");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\nEjecutando ejemplo de 'Listas Doblemente Enlazadas'\n");
            printf("Se crea nodo con valor 3:\n");
            struct Node *head = CrearNodo(3);
            struct Node *cola = NULL;
            printf("Se inserta nodo al inicio con valor 5:\n");
            InsertarAlInicio(&head, 5);
            printf("Se recorre hacia adelante:\n");
            RecorrerHaciaAdelante(head);
            printf("\n");
            printf("Se inserta nodo al inicio con valor 2:\n");
            InsertarAlInicio(&head, 2);
            printf("Se recorre hacia adelante:\n");
            RecorrerHaciaAdelante(head);
            printf("\n");

            printf("Se inserta nodo en la posicion 2 con valor 4 :\n");
            InsertarEnUnaPosicionEspecifica(head, 4, 2);
            RecorrerHaciaAdelante(head);
            printf("\n");
            printf("Se elimina elemento de valor 5:\n");
            EliminarElemento(head, 5);
            RecorrerHaciaAdelante(head);
            printf("\n");
            struct Node *nodoEncontrado = BuscarElemento(head, 3);
            if (nodoEncontrado != NULL) {
                printf("Se encontro el nodo con valor: %d\n", nodoEncontrado->data);
            } else {
                printf("Nodo no encontrado.\n");
            }


            // encontrar cola
            struct Node *head1 = head;
            cola = head;
            while (cola != NULL && cola->next != NULL) {
                cola = cola->next;
            }
            printf("Se inserta nodo al final con valor 10:\n");
            InsertarAlFinal(&cola, 10);

            printf("\nRecorrido hacia atrás:\n");
            RecorrerHaciaAtras(cola);
            printf("\n");

            freeLista(head1);

        } else if (opcion == 2) {
            printf("\nEjecutando ejemplo de 'Stack'\n");
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

        } else if (opcion == 0) {
            printf("Saliendo...\n");
            break;
        } else {
            printf("Opción no existe\n");
        }
    }


    return 0;
}
