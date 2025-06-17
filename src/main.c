#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



//crear nodos
int main () {
        struct Node* head = NULL;
        int data = 5;

        struct Node* nodo1 = (struct Node*)malloc(sizeof(struct Node));
        nodo1->data = data;
        nodo1->next = NULL;

        struct Node* nodo2 = (struct Node*)malloc(sizeof(struct Node));
        nodo2->data = 10;
        nodo2->next = nodo1;

        head = nodo2;


        //incertar al final
        inserfin(&head, 99);

        //ncertar al inicio
        inserInicio(&head, 18);


        //buscar valor
        buscar_valor(&head);



        //imprimir lista
        imprimirlista(head);

        //eliminar un valor
        eliminarnodo(&head);

        imprimirlista(head);

        //elegir posicion
        posicionesp(&head);

        imprimirlista(head);

	   struct Node* temp;
        while (head != NULL) {
                temp = head->next;
                free(head);
                head = temp;
        }

        return 0;
}



