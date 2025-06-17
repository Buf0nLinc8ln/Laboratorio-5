#include <stdio.h>
#include <stdlib.h>
#include "../include/ListasDoblementeEnlazadas.h"

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Node *CrearNodo(int data){

    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void InsertarAlInicio(struct Node **head, int data) {
    struct Node *newNode = CrearNodo(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}   

void InsertarAlFinal(struct Node **cola, int data) {
    struct Node *newNode = CrearNodo(data);
    if (*cola != NULL) {
        newNode->prev = *cola;
        (*cola)->next = newNode;
        *cola = newNode;
    }
}


void InsertarEnUnaPosicionEspecifica(struct Node *head, int data, int posicion) {
    struct Node *newNode = CrearNodo(data);
    int indice = 0;
    struct Node *nodeActual = head;

    while (nodeActual != NULL && indice < posicion) {
        nodeActual = nodeActual->next;
        indice++;
    }

    if (nodeActual != NULL) {
        struct Node *prev = nodeActual->prev;
        newNode->next = nodeActual;
        newNode->prev = prev;
        nodeActual->prev = newNode;
        if (prev != NULL) {
            prev->next = newNode;
        }
    }
}



void EliminarElemento(struct Node *head, int data) {
    
    struct Node *nodeActual = head;
    while(nodeActual != NULL) {
        if (nodeActual->data == data) {
            if (nodeActual->prev != NULL) {
                nodeActual->prev->next = nodeActual->next;
            }
            if (nodeActual->next != NULL) {
                nodeActual->next->prev = nodeActual->prev;
            }
            free(nodeActual);
            return;
        }
        nodeActual = nodeActual->next;
    }

}

struct Node *BuscarElemento(struct Node *head, int data) {
    
    struct Node *nodeActual = head;
    while(nodeActual != NULL) {
        if (nodeActual->data == data) {
            return nodeActual;
        }
        nodeActual = nodeActual->next;
    }
    return NULL;
}


void RecorrerHaciaAdelante(struct Node *head) {
    
    struct Node *nodeActual = head;
    while(nodeActual != NULL) {
        printf("%d ", nodeActual->data);
        nodeActual = nodeActual->next;

    }

}

void RecorrerHaciaAtras(struct Node *cola) {
    
    struct Node *nodeActual = cola;
    while(nodeActual != NULL) {
        printf("%d ", nodeActual->data);
        nodeActual = nodeActual->prev;

    }

}

void freeLista(struct Node *head) {
    struct Node *nodeActual = head;
    while (nodeActual != NULL) {
        struct Node *nodoSiguiente = nodeActual->next;
        free(nodeActual);
        nodeActual = nodoSiguiente;
    }
}