#ifndef LISTASDOBLEMENTEENLAZADAS_H
#define LISTASDOBLEMENTEENLAZADAS_H

struct nodeDoble {
    int data;
    struct nodeDoble *next;
    struct nodeDoble *prev;
};

struct nodeDoble *CrearNodo(int data);
void InsertarAlInicio(struct nodeDoble **head, int data);
void InsertarAlFinal(struct nodeDoble **cola, int data);
void InsertarEnUnaPosicionEspecifica(struct nodeDoble *head, int data, int posicion);
void EliminarElemento(struct nodeDoble *head, int data);
struct nodeDoble *BuscarElemento(struct nodeDoble *head, int data);
void RecorrerHaciaAdelante(struct nodeDoble *head);
void RecorrerHaciaAtras(struct nodeDoble *cola);
void freeLista(struct nodeDoble *head);

#endif