#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *rut;
    char *nombre;
    int disponibilidad[7];
}Bombero;

void copiarCadena(Bombero *b, Bombero *vector, unsigned long long j){
    unsigned long long i, tallaCadena = 0;

    vector[j].rut = (char *) malloc(10 * sizeof(char) );
    if(vector[j].rut == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }

    vector[j].nombre = (char *) malloc(100 * sizeof(char) );
    if(vector[j].nombre == NULL){
        printf("No hay suficiente espacio en la memoria\n"); exit(1);
    }

    //Se guarda rut//
    for(i = 0; b->rut[i]; i++){
        vector[j].rut[i] = b->rut[i];
        tallaCadena++;
    }

    vector[j].rut[tallaCadena] = '\0';
    tallaCadena = 0;

    //Se guarda nombre//
    for(i = 0; b->nombre[i]; i++){
        vector[j].nombre[i] = b->nombre[i];
        tallaCadena++;
    }

    vector[j].nombre[tallaCadena] = '\0'; 
    return;
}
