#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "empleado.h"



void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
 for (int i=0; i<tam; i++)
 {
     almuerzos[i].isEmpty =1;
 }
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom){
    char nombreEmpleado[20];
    char nombreComida [20];

    cargarNombreEmpleado(nombreEmpleado,almuerzo.idEmpleado, empleados, tamEmp);
    cargarDescripcionComida(nombreComida, almuerzo.idComida, comidas, tamCom);

    printf(" %d    %d   %s    %s    %d/%d/%d\n\n", almuerzo.id, almuerzo.idEmpleado, nombreEmpleado, nombreComida, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
}
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom){
 int flag=0;

 system("cls");
 printf("*** Listado almuerzos ***\n");
 printf("ID   IdEmpleado    Nombre    Comida    Fecha \n\n");
 for (int i=0; i<tama; i++)
 {
     if(almuerzos[i].isEmpty ==0 )
     {
         mostrarAlmuerzo(almuerzos[i], empleados,tamEmp, comidas, tamCom);
         flag=1;
     }
 }
 if(flag == 0)
 {
     printf("No hay almuerzos cargados \n");
 }
}
//--------------------------------------------------------------

int buscarLibreAlmuerzo (eAlmuerzo vec[], int tam)
{
    int indice= -1;
    for (int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//---------------------------------------------------------------------

int altaAlmuerzo(int id, eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom){
 int todoOk =0;
 int indice;
 eAlmuerzo nuevoAlmuerzo;

 system("cls");
 printf("***Alta almuerzo***\n");

 indice = buscarLibreAlmuerzo (almuerzos, tama);

 if(indice == -1)
 {
     printf("No hay lugar para otro almuerzo\n");
 }else{
    mostrarEmpleados(empleados,tam, sectores, tamSec);
    printf("Ingrese el id del empleado: \n");
    scanf("%d", &nuevoAlmuerzo.idEmpleado);

    mostrarComidas(comidas, tamCom);
    printf("Ingrese id comida: \n");
    scanf("%d", &nuevoAlmuerzo.idComida);

    printf("Ingrese fecha: dd/mm/aaaa\n");
    scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes ,&nuevoAlmuerzo.fecha.anio);

    nuevoAlmuerzo.isEmpty=0;
    nuevoAlmuerzo.id = id;

    almuerzos[indice] = nuevoAlmuerzo;
    todoOk = 1;
 }

 return todoOk;
}

