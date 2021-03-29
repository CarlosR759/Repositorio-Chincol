#include <stdio.h>

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void mostrarTodosLosBomberosDeLaEstacion(Bombero *vector, unsigned long long talla){   
    unsigned long long i;
    int j = 0;
    for(i = 0; i < talla; i++){
        printf("%s  ", vector[i].rut);
        printf("%s  ", vector[i].nombre);
        for(j = 0; j < 7; j++) printf("%d ", vector[i].disponibilidad[j] );

        printf("\n");
    }

    return;
}