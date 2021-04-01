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

typedef List list;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
    return list;
}

void * firstList(List * list) {
    if (list == NULL){
      return NULL;
    }
    if (list->head == NULL){
      return NULL;
    }
    list->current = list->head;
    return (void *)list->current->data;
}

void * nextList(List * list) {
    if (list->current == NULL){
      return NULL;
    }
    if (list->current->next == NULL){
      return NULL;
    }
    list->current = list->current->next;
    return (void *)list->current->data;
}

void * lastList(List * list) {
    if (list == NULL){
      return NULL;
    }
    if (list->tail == NULL){
      return NULL;
    }
    list->current = list->tail;
    return (void *)list->current->data;
}

void * prevList(List * list) {
    if (list->current == NULL){
      return NULL;
    }
    if (list->current->prev == NULL){
      return NULL;
    }
    list->current = list->current->prev;
    return (void *)list->current->data;
}

void pushFront(List * list, const void * data) {
    Node* NodoNuevo = createNode(data);
    if (list->head == NULL){
      list->head = NodoNuevo;
      list->tail = list->head;
    }else{
      NodoNuevo->next = list->head;
      list->head->prev = NodoNuevo;
      list->head = NodoNuevo;
      NodoNuevo->prev = NULL;
    }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
    Node* NodoNuevo = createNode(data);
    if(NodoNuevo == NULL){
      printf("No hay memoria\n");
      exit (1);
    }
    if (list->current->next == NULL){
      list->current->next = NodoNuevo;
      NodoNuevo->prev = list->current;
      list->current = NodoNuevo;
      list->tail = list->current;
    }else{
      list->current->next = NodoNuevo;
      NodoNuevo->prev = list->current;
      list->current = NodoNuevo;
    }
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
    Node* eliminado = (Node*)malloc(sizeof(Node));
    int long datoEliminado;
    eliminado = list->current;
    datoEliminado = (int long)eliminado->data;
    // Eliminar el primer nodo.
    if (list->current->prev == NULL){
      list->head = list->current->next;
      list->head->prev = NULL;
      list->current = list->head;
      free(eliminado);
      return (void *)datoEliminado;
    }
    // Eliminar el último nodo.
    if (list->current->next == NULL){
      list->tail = list->current->prev;
      list->tail->next = NULL;
      list->current = list->tail;
      free(eliminado);
      return (void *)datoEliminado;
    }
    // Eliminar el nodo en la posición del current.
    else{
      list->current->next->prev = list->current->prev;
      list->current->prev->next = list->current->next;
      free(eliminado);
      return (void *)datoEliminado;
    }   
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}