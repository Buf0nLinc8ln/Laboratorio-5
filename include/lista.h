#ifndef LISTA_H
#define LISTA_H

struct Node {
        int data;
        struct Node* next;

};

void inserInicio(struct Node ** head, int valor);
void imprimirlista(struct Node* head);
void inserfin(struct Node ** head, int valor);
void posicionesp(struct Node **head);
void eliminarnodo(struct Node **head);
void buscar_valor(struct Node** head);


#endif
