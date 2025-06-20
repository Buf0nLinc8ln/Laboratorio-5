#include <stdio.h>
#include <stdlib.h>
#include "../include/ListasDoblementeEnlazadas.h"




struct nodeDoble *CrearNodo(int data){

    struct nodeDoble* newNode = (struct nodeDoble *)malloc(sizeof(struct nodeDoble));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void InsertarAlInicio(struct nodeDoble **head, int data) {
    struct nodeDoble *newNode = CrearNodo(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}   

void InsertarAlFinal(struct nodeDoble **cola, int data) {
    struct nodeDoble *newNode = CrearNodo(data);
    if (*cola != NULL) {
        newNode->prev = *cola;
        (*cola)->next = newNode;
        *cola = newNode;
    }
}


void InsertarEnUnaPosicionEspecifica(struct nodeDoble *head, int data, int posicion) {
    struct nodeDoble *newNode = CrearNodo(data);
    int indice = 0;
    struct nodeDoble *nodeActual = head;

    while (nodeActual != NULL && indice < posicion) {
        nodeActual = nodeActual->next;
        indice++;
    }

    if (nodeActual != NULL) {
        struct nodeDoble *prev = nodeActual->prev;
        newNode->next = nodeActual;
        newNode->prev = prev;
        nodeActual->prev = newNode;
        if (prev != NULL) {
            prev->next = newNode;
        }
    }
}



void EliminarElemento(struct nodeDoble *head, int data) {
    
    struct nodeDoble *nodeActual = head;
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

struct nodeDoble *BuscarElemento(struct nodeDoble *head, int data) {
    
    struct nodeDoble *nodeActual = head;
    while(nodeActual != NULL) {
        if (nodeActual->data == data) {
            return nodeActual;
        }
        nodeActual = nodeActual->next;
    }
    return NULL;
}


void RecorrerHaciaAdelante(struct nodeDoble *head) {
    
    struct nodeDoble *nodeActual = head;
    while(nodeActual != NULL) {
        printf("%d ", nodeActual->data);
        nodeActual = nodeActual->next;

    }

}

void RecorrerHaciaAtras(struct nodeDoble *cola) {
    
    struct nodeDoble *nodeActual = cola;
    while(nodeActual != NULL) {
        printf("%d ", nodeActual->data);
        nodeActual = nodeActual->prev;

    }

}

void freeLista(struct nodeDoble *head) {
    struct nodeDoble *nodeActual = head;
    while (nodeActual != NULL) {
        struct nodeDoble *nodoSiguiente = nodeActual->next;
        free(nodeActual);
        nodeActual = nodoSiguiente;
    }
}