#ifndef LISTA_H
#define LISTA_H

struct nodeSimple {
        int data;
        struct nodeSimple* next;

};

void inserInicio(struct nodeSimple ** head, int valor);
void imprimirlista(struct nodeSimple* head);
void inserfin(struct nodeSimple ** head, int valor);
void posicionesp(struct nodeSimple **head);
void eliminarnodo(struct nodeSimple **head);
void buscar_valor(struct nodeSimple** head);


#endif
