#ifndef LISTASDOBLEMENTEENLAZADAS_H
#define LISTASDOBLEMENTEENLAZADAS_H

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *CrearNodo(int data);
void InsertarAlInicio(struct Node **head, int data);
void InsertarAlFinal(struct Node **cola, int data);
void InsertarEnUnaPosicionEspecifica(struct Node *head, int data, int posicion);
void EliminarElemento(struct Node *head, int data);
struct Node *BuscarElemento(struct Node *head, int data);
void RecorrerHaciaAdelante(struct Node *head);
void RecorrerHaciaAtras(struct Node *cola);

#endif