#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Bombero *datos;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

typedef struct{
    char *rut;
    char *nombre;
    int disponibilidad[7];
}Bombero;

void copiarCadena(Bombero *b, List *list,unsigned long long j){
    unsigned long long i, tallaCadena = 0;

    //se guarda rut//
    for(i = 0; b->rut[i]; i++){
        list->head->datos->rut[i] = b->rut[i];
        tallacadena++;
    }

    list->head->rut[tallaCadena] = '\0';
    tallaCadena = 0;

    //Se guarda nombre//
    for(i = 0; b->nombre[i]; i++){
        list->head->datos->nombre[i] = b->nombre[i];
        tallaCadena++;
    }

    list->head->datos->nombre[tallaCadena] = '\0'; 
    return;
}