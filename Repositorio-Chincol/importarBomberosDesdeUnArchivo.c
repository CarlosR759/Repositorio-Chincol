#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void copiarCadena(Bombero *b, Bombero *vector, unsigned long long j);

char *get_csv_field (char * tmp, int k){
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}

Bombero *importarBomberosDesdeUnArchivo(char * bomberos, unsigned long long *talla){
    FILE *fp = fopen("bomberos.csv","r");
    char linea[1000];
    char *aux;
    Bombero *b =(Bombero*)malloc(sizeof(Bombero));
    Bombero *vector = NULL;
    b->rut = malloc(10*sizeof(char));
    b->nombre = malloc(100*sizeof(char));
    int i, j = 0;

    while(fgets (linea, 1000, fp) != NULL){
        vector = (Bombero *) realloc(vector, (j+1) *sizeof(Bombero) );
        if(vector == NULL){
            printf("No hay suficiente espacio en la memoria\n"); exit(1);
        }


        for( i = 0; i < 9; i++) {
            if(i==0){
              b->rut = get_csv_field(linea,i);
              printf("%s ", b->rut);
            }
            if(i==1){
              b->nombre = get_csv_field(linea,i);
              printf("%s ", b->nombre);
            }

            if(i==2){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[1] = 1;
              }else vector[j].disponibilidad[0] = 0;
              printf("%d ", vector[j].disponibilidad[0]);
            }
            if(i==3){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[1] = 1;
              }else vector[j].disponibilidad[1] = 0;
              printf("%d ", vector[j].disponibilidad[1]);

            }
            if(i==4){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[2] = 1;
              }else vector[j].disponibilidad[2] = 0;
             
              printf("%d ", vector[j].disponibilidad[2]);

            }
            if(i==5){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[3] = 1;
              }else vector[j].disponibilidad[3] = 0;
             
              printf("%d ", vector[j].disponibilidad[3]);

            }
            if(i==6){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[4] = 1;
              }else vector[j].disponibilidad[4] = 0;

              printf("%d ", vector[j].disponibilidad[4]);
             
            }
            if(i==7){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[5] = 1;
              }else vector[j].disponibilidad[5] = 0;
             
              printf("%d ", vector[j].disponibilidad[5]);

            }
            if(i==8){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                vector[j].disponibilidad[6] = 1;
              }else vector[j].disponibilidad[6] = 0;
             
              printf("%d ", vector[j].disponibilidad[6]);

            }

        }
       
        //Copiamos rut y nombre a vector. 
        copiarCadena(b,vector, j);
 
        j++;
        printf("\n\n");
    }

    (*talla) = j;
    return vector;
}