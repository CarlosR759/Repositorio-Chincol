#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

int main(void){
    importarBomberosDesdeUnArchivo("info_Bomberos.txt");
    int opcion, i;
    Bombero *b = (Bombero*)malloc(sizeof(Bombero));
    printf("Estación de bomberos\n");
    printf("1. Agregar Bombero\n");
    printf("2. Despedir Bombero\n");
    printf("3. Buscar Bombero por día\n");
    printf("4. Buscar Bombero por Rut\n");
    printf("5. Modificar disponibilidad de un Bombero\n");
    printf("6. Crear horario de la semana\n");
    printf("7. Mostrar horario de la semana\n");
    printf("8. Mostrar todods los Bomberos\n");
    printf("0. Salir\n");
    scanf("%d", &opcion);
    while(opcion<0 || opcion>9){
      scanf("%d", &opcion);
    }







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

    




    return 0;
}