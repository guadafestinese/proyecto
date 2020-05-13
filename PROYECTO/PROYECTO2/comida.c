#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"



void mostrarComidas(eComida comidas[], int tam){
printf("Listado de comidas\n");
printf ("ID Descripcion   Precio\n");
for(int i=0; i<tam; i++)
    {
        printf(" %d   %10s   %5.2f\n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);
    }
}


int cargarDescripcionComida(char descripcion[], int id, eComida comidas[],int tam){
    int todoOk =0;
    for (int i=0; i<tam; i++)
    {
        if(comidas[i].id == id)
        {
            strcpy(descripcion, comidas[i].descripcion);
            todoOk=1;
        }
    }
    return todoOk;
}

