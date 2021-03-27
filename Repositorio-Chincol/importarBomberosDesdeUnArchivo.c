#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;
void importarBomberosDesdeUnArchivo(char * bomberos){
    FILE *fp = fopen("bomberos.csv","r");
    char linea[1000];
    Bombero *b =(Bombero*)malloc(100*sizeof(Bombero));
    b->rut = malloc(10*sizeof(char));
    b->nombre = malloc(100*sizeof(char));
    int i,k;
    k=0;
    while(fgets (linea, 1000, fp) != NULL){
        for( i = 0, i < 9; i++){
            if(i==0){
              b[k].rut = get_csv_field(linea,i);
            }
            if(i==1){
              b[k].nombre = get_csv_field(linea,i);
            }
            if(i==2){
              b[k].disponibilidad[0]=get_csv_field(linea,i);
            }
            if(i==3){
              b[k].disponibilidad[1]=get_csv_field(linea,i);
            }
            if(i==4){
              b[k].disponibilidad[2]=get_csv_field(linea,i);
            }
            if(i==5){
              b[k].disponibilidad[3]=get_csv_field(linea,i);
            }
            if(i==6){
              b[k].disponibilidad[4]=get_csv_field(linea,i);
            }
            if(i==7){
              b[k].disponibilidad[5]=get_csv_field(linea,i);
            }
            if(i==8){
              b[k].disponibilidad[6]=get_csv_field(linea,i);
            }
        }
        k++;
    }


    return;
}