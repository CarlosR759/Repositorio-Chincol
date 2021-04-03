#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *lista = (List *) malloc(sizeof(List) );
    if(lista == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;

     return lista;
}

void * firstList(List * list) {
    list->current = list->head; 
    return (void *)list->head->data;
}

void * nextList(List * list) {
    if( (list->current) && (list->current->next != NULL) )
        list->current = list->current->next;
    else
        return NULL;

    return (void *)list->current->data;
}

void * lastList(List * list) {
    list->current = list->tail; 
    return (void *)list->tail->data;
}

void * prevList(List * list) {
    if( (list->current) && (list->current->prev != NULL) )
        list->current = list->current->prev; 
    else
        return NULL;

    return (void *) list->current->data;
}

void pushFront(List * list, const void * data) {
    Node *nuevoNodo = createNode( (void *) data); 
    
    if(nuevoNodo == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }
    // Si no hay nodos en la lista se actualizan datos de list//
    if(list->head == NULL){
        list->head = nuevoNodo;
        list->tail = nuevoNodo;
        return;
    }

    // Si ya hay elemtos en la lista se ejecutan las siguientes instrucciones //
    list->head->prev = nuevoNodo;
    nuevoNodo->next = list->head;
    list->head = nuevoNodo;

    return;
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
    Node *nodoNuevo = createNode( (void *) data);
    if(nodoNuevo == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }
    nodoNuevo->prev = list->current;

    //Cuando current es cola de la lista//
    if(list->current->next == NULL){
        list->current->next = nodoNuevo;
        nodoNuevo->prev = list->current;
        list->current = nodoNuevo;
        list->tail = list->current;

    //Cuando current está entre medio// 
    }else{
        list->current->next = nodoNuevo;
        nodoNuevo->next = list->current->next->next; //Lineanueva;
        nodoNuevo->prev = list->current;
        list->current = nodoNuevo;
    }


    return;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    Node *nodoABorrar = (Node *)  malloc(sizeof(Node) );
    long int *numero = NULL;

    if(nodoABorrar == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);;
    }

    nodoABorrar = list->current;

    //Caso head//
    if(nodoABorrar->prev == NULL){
        list->head = list->current->next;
        list->head->prev = NULL;
        list->current = list->head;
        nodoABorrar->next = NULL;
        nodoABorrar->prev = NULL;
        numero = (long int *) nodoABorrar->data;
        free(nodoABorrar); 
        return (void *) numero;

    //Caso cola //
    }else if(nodoABorrar->next == NULL){
        list->tail = list->current->prev;
        list->current = list->tail;
        list->tail->next = NULL;
        nodoABorrar->prev = NULL;
        nodoABorrar->next = NULL;
        numero = (long int *) nodoABorrar->data;
        free(nodoABorrar);
        return (void *) numero; 

    //Caso cuando nodo está al medio//
    }else{
        list->current->next->prev = list->current->prev;
        list->current->prev->next = list->current->next;
        nodoABorrar->prev = NULL;
        nodoABorrar->next = NULL;
        numero = (long int *) nodoABorrar->data;
        free(nodoABorrar);
        return (void *) numero;
    }

    
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
