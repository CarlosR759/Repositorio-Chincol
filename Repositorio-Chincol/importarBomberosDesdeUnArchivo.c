#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;


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

Bombero *importarBomberosDesdeUnArchivo(char *bomberos, unsigned long long *talla){
    FILE *fp = fopen("bomberos.csv","r");
    char linea[1000];
    char *aux;
    Bombero *b =(Bombero*)malloc(sizeof(Bombero));
    Bombero *vector = NULL;
    b->rut = malloc(10*sizeof(char));
    b->nombre = malloc(100*sizeof(char));
    int i, j = 0;

    while(fgets (linea, 1000, fp) != NULL){
        //Creamos nodo en lista e inicializamos la memoria en el struct Bombero *datos//
        list = pushFront(list); 
        list->head->datos->rut = (char *) malloc(10 * sizeof(char *) );
        if(list->head->datos->rut == NULL){ printf("Error en inicializar rut\n"); exit(1); }
        list->head->datos->nombre = (char *) malloc(100 * sizeof(char *) );
        if(list->head->datos->nombre == NULL){ printf("Error en inicializar nombre\n"); exit(1); }



        //Se lee desde el archivo cvs los datos de las personas y se van agregando a la 'list'//
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
                list->head->datos->disponibilidad[0] = 1;
              }else list->head->datos->disponibilidad[0] = 0;
              printf("%d ", list->head->datos->disponibilidad[0]);
            }
            if(i==3){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[1] = 1;
              }else list->head->datos->disponibilidad[1] = 0;
              printf("%d ", list->head->datos->disponibilidad[1]);

            }
            if(i==4){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[2] = 1;
              }else list->head->datos->disponibilidad[2] = 0;
              printf("%d ", vector[j].disponibilidad[2]);

            }
            if(i==5){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[3] = 1;
              }else list->head->datos->disponibilidad[3] = 0;
             
              printf("%d ", list->head->datos->disponibilidad[3]);

            }
            if(i==6){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[4] = 1;
              }else list->head->datos->disponibilidad[4] = 0;

              printf("%d ", list->head->datos->disponibilidad[4]);
             
            }
            if(i==7){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[5] = 1;
              }else list->head->datos->disponibilidad[5] = 0;
             
              printf("%d ", list->head->datos->disponibilidad[5]);

            }
            if(i==8){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                list->head->datos->disponibilidad[6] = 1;
              }else list->head->datos->disponibilidad[6] = 0;
             
              printf("%d ", list->head->datos->disponibilidad[6]);

            }

        }
       
        //Copiamos rut y nombre a vector. 
        int i tallaCadena = 0;
       
        //se guarda rut//
        for(i = 0; b->rut[i]; i++){
          list->head->datos->rut[i] = b->rut[i];
          tallaCadena++;
        }

        list->head->rut[tallaCadena] = '\0';
        tallaCadena = 0;

        //Se guarda nombre//
        for(i = 0; b->nombre[i]; i++){
          list->head->datos->nombre[i] = b->nombre[i];
          tallaCadena++;
        }

        list->head->datos->nombre[tallaCadena] = '\0'; 
 
        //copiarCadena(b,list, j);
 
        j++;
        printf("\n\n");
    }

    (*talla) = j;
    return vector;
}