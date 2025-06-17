#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node* next;

};


//funcion para agregar nuevo elemento al inicio de la lista
void inserInicio(struct Node ** head, int valor) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = valor;
        newNode->next = *head;
        *head = newNode;
}

//imprimir la lista luego de agregar nodo
void imprimirlista(struct Node* head) {
        struct Node *actual;
        printf("\nla lista es:\n");
        for(actual = head; actual != NULL; actual = actual->next)
                printf("%d ->", actual->data);
        printf("NULL\n\n");
}

//funcion para agregar nodo al final
void inserfin(struct Node ** head, int valor) {
        struct Node* newNode = malloc(sizeof(struct Node));

        newNode->data = valor;
        newNode->next = NULL;

        if (*head == NULL) {
                *head = newNode;
        } else {
                struct Node* temp = *head;
                while (temp->next != NULL) {
                        temp =temp->next;
                }
                temp->next = newNode;
        }
}





//incertar en posicion especifica
void posicionesp(struct Node **head) {
        int valor;
        int posicion;
        int i;

        printf("\nValor de nuevo nod:\n");
        scanf("%d", &valor);
        printf("Posicion del nuevo nodo (0 para inicio):\n");
        scanf("%d", &posicion);

        struct Node*  newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = valor;
        newNode->next = NULL;

        if (posicion == 0) {
                newNode->next = *head;
                *head = newNode;
                return;
        }

        struct Node *temp = *head;
        for (i = 0; temp != NULL && i < posicion -1; i++) {
                temp = temp->next;
        }

        if (temp == NULL) {
                printf("Posicion no valida\n");
                return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
}


//eliminar nodo de lista enlazada basado en el data
void eliminarnodo(struct Node **head) {
        int borrar_valor;
        printf("\nIngrsar valor a eliminar:\n");
        scanf("%d", &borrar_valor);

        struct Node *actual = *head;
        struct Node *anterior = NULL;

        for (actual = *head; actual != NULL && actual->data !=borrar_valor; actual = actual->next) {
                anterior = actual;
        }

        if (actual == NULL) {
                printf("El valor %d no esta en la lista", borrar_valor);
                return;
        }

        if (anterior == NULL) {
                *head = actual->next;
        } else {
                anterior->next = actual->next;
        }
}


//buscar elemento (utilizar el data) recorrer con for como el anteiror mas facil
void buscar_valor(struct Node** head) {
        int valor_buscado;
        printf("\nIngresar valor a buscar:");
        scanf("%d", &valor_buscado);

        struct Node* actual;
        for(actual = *head; actual != NULL; actual = actual->next){
               if (actual->data == valor_buscado) {
               printf("\nEl valor %d si se encuentra en la lista \n", valor_buscado);
               return;
               }
        }
        printf("el valor %d no se encuentra en la lista", valor_buscado);
}





