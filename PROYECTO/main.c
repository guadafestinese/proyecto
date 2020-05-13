#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "infoEmpleados.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"
#include "sector.h"

#define TAM 10
#define TAMSECTOR 4
#define TAMC 3
#define TAMA 4
#define CANTHARCODE 5



int main()
{
    char seguir = 's';
    char confirma = 's';
    int proximoId = 1000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eSector sectores[TAMSECTOR] = {{1, "Sistemas"}, {2, "RRHH"}, {3, "Ventas"}, {4, "Compras"} };
    eComida comidas[TAMC] = { {100, "Milanesas", 150}, {101, "Albondigas", 200}, {103, "Fideos", 120} };
    eAlmuerzo almuerzos[TAMA];

    inicializarEmpleados(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMA);
    hardcodear(lista, CANTHARCODE);
    proximoId = proximoId + CANTHARCODE;

    switch(menu()){

    case 1:
        if(altaEmpleado(proximoId, lista, TAM, sectores, TAMSECTOR))
        proximoId ++;
        break;
    case 2:
        modificarEmpleado(lista, TAM, sectores, TAMSECTOR);
        break;
    case 3:
        bajaEmpleado(lista, TAM, sectores, TAMSECTOR);
        break;
    case 4:
        ordenarEmpleados(lista,TAM);
        break;
    case 5:
        mostrarEmpleados(lista, TAM, sectores, TAMSECTOR);
        break;
    case 6:
        informeEmpleados(lista, TAM, sectores, TAMSECTOR);
        break;
    case 7:
        mostrarAlmuerzos(almuerzos, TAMA, lista, TAM, comidas, TAMC);
        break;

    case 10:
        printf("Confirma salida?: \n");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            seguir = 'n';
        }
        break;


    }//fin swirch
    return 0;
}
