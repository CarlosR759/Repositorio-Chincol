#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void menu(int *opcion);
Bombero *importarBomberosDesdeUnArchivo(char *, unsigned long long *talla);
void copiarCadena(Bombero *b, Bombero *vector, unsigned long long j);
Bombero *agregarBombero(char rut[10], char *nombre, int disponibilidad[] ){
void eliminarBomberos(char *rut){
//void buscarBomberosDisponiblesPorDia(char *dia){
//void buscarBomberosPorRut(char *rut){
//void modificarDisponibilidadDeUnBombero(char *rut, int disponibilidad[] ){
//void crearHorarioSemanal(void){
//void mostrarHorarioDeLaSemana(void ){
void mostrarTodosLosBomberosDeLaEstacion(Bombero *vector, unsigned long long talla);


int main(void){
    int opcion = 0, i = 0;
    unsigned long long talla;
    Bombero *vector = NULL;
    char rut[10];



    vector = importarBomberosDesdeUnArchivo("bomberos.csv", &talla);

    do{
        menu(&opcion);
        getchar();
        if(opcion == 0) break;
        //if(opcion == 1) agregarBombero();
        if(opcion == 2) eliminarBomberos(rut,vector,talla); 
        //if(opcion == 3) buscarBomberosDisponiblePorDia();  
        //if(opcion == 4) buscarBomberosPorRut(); 
        //if(opcion == 5) modificarDisponibilidadDeUnBombero(); 
        //if(opcion == 6) crearHorarioSemanal();
        //if(opcion == 7) mostrarHorarioDelaSemana(); 
        if(opcion == 8) mostrarTodosLosBomberosDeLaEstacion(vector, talla);

        printf("\n\n");
    }while(opcion != 0);


    printf("TOTAL BOMBEROS: %llu\n", talla);


    //Bombero *b = (Bombero*)malloc(sizeof(Bombero));
   
    //importarBomberosDesdeUnArchivo("info_Bomberos.txt");






/*
    switch(opcion){
      case 1: scanf("%s %s", b->rut, b->nombre);
              for(i = 0; i < 7; i++){
                scanf("%d", &b->disponibilidad[i]);
              }
              agregarBombero(b->rut,b->nombre,b->disponibilidad);
      break;
      case 2: eliminarBomberos();
      break;
      case 3: buscarBomberosDisponiblesPorDia();
      break;
      case 4: buscarBomberosPorRut();
      break;
      case 5: modificarDisponibilidadDeUnBombero();
      break;
      case 6: crearHorarioSemanal();
      break;
      case 7: mostrarHorarioDeLaSemana();
      break;
      case 8: mostrarTodosLosBomberosDeLaEstacion();
      break;
      case 0:
      break;
    }

 */   




    return 0;
}
