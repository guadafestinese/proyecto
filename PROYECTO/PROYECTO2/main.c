#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "infoEmpleados.h"
#include "almuerzo.h"
#include "datawarehouse.h"
#include "comida.h"




#define TAM 10
#define TAMSECTOR 5
#define TAMC 3
#define TAMA 4
#define CANTHARDCODE 5



int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eSector sectores[TAMSECTOR] = {{1, "Sistemas"}, {2, "RRHH"}, {3, "Compras"}, {4, "Ventas"}, {5, "Contable"} };
    eComida comidas[TAMC] = { {100, "Milanesas", 150}, {101, "Albondigas", 200}, {103, "Fideos", 120} };
    eAlmuerzo almuerzos[TAMA];

    inicializarEmpleados(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMA);
    hardcodear(lista, CANTHARDCODE);
    proximoId += CANTHARDCODE;

    do{


    switch(menu()){

    case 1:
        if(altaEmpleado(proximoId, lista, TAM, sectores, TAMSECTOR)){
           proximoId ++;
        }

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
    case 8:
        if(altaAlmuerzo(proximoIdAlmuerzo, almuerzos, TAMA, lista, TAM, sectores, TAMSECTOR, comidas, TAMC))
        {
            proximoIdAlmuerzo++;
        }
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
    }while(seguir == 's');
    return 0;
}
