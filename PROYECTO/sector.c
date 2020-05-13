#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "infoEmpleados.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"
#include "sector.h"

#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
int id;
char descripcion [20];
}eSector;

#endif // SECTOR_H_INCLUDED
void listarSectores(eSector sectores[], int tamSector)
{
    system("cls");
    printf("\n*** Listado de sectores ***\n\n");
    printf("   Id       Descripcion\n");
    for (int i=0; i< tamSector; i++)
    {
       printf("    %d    %10s",sectores[i].id, sectores[i].descripcion);
    }
    printf("\n\n");
}

//-------------------------------------------------------------------------

int cargarDescripcionSector (char descripcion[], int id, eSector sectores[], int tamsec){
int todoOk=0;
	for (int i=0; i<tamsec; i++){
	if (sectores[i].id == id){
	strcpy(descripcion, sectores[i].descripcion);
	todoOk=1;
	}
	}
	return todoOk;
}

//-------------------------------------------------------------------------------------------


