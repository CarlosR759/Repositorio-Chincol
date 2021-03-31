#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
}Bombero;

void eliminarBomberos(char *rut, Bombero *vector, unsigned long long *talla){
  printf("Ingrese rut del bombero a despedir: ");
  scanf("%[^\n]s", rut);
  getchar();
    int j, i, n;
    bool encontrado;
    for( j = 0; j < *talla; j++){
        i = 0;
        encontrado = true;
        while(vector[j].rut[i] != '\0' && encontrado){
            if(vector[j].rut[i] != rut[i]){
                encontrado = false; 
            }
            i++;
        }
        if(encontrado){
            for( n = j; n < *talla - 2; n++ ){
                for(i = 0; vector[n+1].rut[i]; i++){
                    vector[n].rut[i] = vector[n+1].rut[i];
                }
                vector[n].rut[i] = '\0';
                for(i = 0; vector[n+1].nombre[i]; i++){
                    vector[n].nombre[i] = vector[n+1].nombre[i];
                }
                vector[n].nombre[i] = '\0';
                for(i = 0; i < 7; i++){
                    vector[n].disponibilidad[i] = vector[n+1].disponibilidad[i];
                }
            }
            vector = realloc (vector, (*talla-1) * sizeof(Bombero));
            printf("-----------------------\n");
            printf("Bombero eliminado\n");
            printf("-----------------------\n");
            return;
        }
    }
    if(!encontrado){
        printf("NO EXISTE BOMBERO\n");
    }
}