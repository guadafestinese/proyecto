#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infoEmpleados.h"



//(1)-------------------------------------------------------------------------------------------
void informeEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{

    char seguir = 's';
    char confirma = 's';

    do
    {
        switch(menuInformes())
        {
        case 'a':
            listarEmpleadosPorAnio(vec, tam, sectores, tamsec);
            break;
        case 'b':
            listarEmpleadas(vec,tam, sectores, tamsec);
            break;
        case 'c':
            informarTotalSueldos(vec,tam);
            break;
        case 'd':
            informarEmpleadosDeSector(vec, tam, sectores, tamsec);
            break;
        case 'e':
            informarEmpleadosXSector(vec,tam,sectores,tamsec);
            break;
        case 'f':
            informarMayorSueldoSector(vec,tam, sectores,tamsec);
            break;
        case 'g':
            informarEmpleadoCostosoSector(vec,tam,sectores,tamsec);
            break;
        case 'h':
            aumentarSueldosSector(vec,tam,sectores,tamsec);
            break;
        case'i':
            informarSectorCostoso(vec,tam,sectores,tamsec);
            break;
        case 'j':
            informarTotalSueldosSector(vec,tam,sectores, tamsec);
            break;
        case 'k':
            cantidadEmpleadosSector(vec,tam,sectores,tamsec);
            break;
        case 'l':
            informarEmpleadoMasJovenSector(vec,tam,sectores,tamsec);
            break;

        case 'x':
            printf("Confirma salida?: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");

    }
    while ( seguir == 's');

}

//(2)--------------------------------------------------------------------
char menuInformes()
{
    char opcion;
    system("cls");
    printf("*********** Informes ***********\n");
    printf("a- Listar empleados por anio de ingreso\n");
    printf("b- Listado de empleadas\n");
    printf("c- Total sueldos\n");
    printf("d- Informar empleados de un sector\n");
    printf("e- Informar empleados de todos los sectores\n");
    printf("f- Informar mayor sueldo sector\n");
    printf("g- Empleados costosos de sector \n");
    printf("h- Actualizar sueldos sector \n");
    printf("i- Informar sector costoso \n");
    printf("j- Total sueldos sector \n");
    printf("k- Cantidad de empleados de todos los sectores \n");
    printf("l- Empleado mas joven sector \n");
    printf("x. Salir\n");


    printf("Ingrese una opcion:");
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}
//(a)------------------------------------------------
void listarEmpleadosPorAnio(eEmpleado vec[], int tam,eSector sectores[], int tamsec)
{
    int anio;
    int flag = 0;

    system("cls");
    printf("**** Listado de empleados por anio de ingreso ****\n\n");
    printf("\n Ingrese anio:");
    scanf("%d", &anio);

    printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso\n");

    for (int i=0; i< tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].fechaIngreso.anio == anio)
        {
            mostrarEmpleado(vec[i], sectores, tamsec);
            flag = 1;
        }
    }

    if ( flag == 0)
    {
        printf("\nNo hay empleados que hayan ingresado ese anio. \n");
    }

}
//(b)-------------------------------------------------------------
void listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int hayEmpleadas = 0;
    printf("\n***** Listado Empleadas *****\n\n");
    printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso\n");

    for (int i=0; i< tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].sexo == 'f')
        {
            mostrarEmpleado(vec[i], sectores, tamsec);
            hayEmpleadas = 1;
        }
    }

    if ( hayEmpleadas == 0)
    {
        printf("\nNo hay empleadas mujeres   que listar \n");
    }

}

//(c)----------------------------------------------------
/*void informarTotalSueldosSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec)
{
    float total=0;
    system("cls");
    printf("***** Informe total sueldos a pagar *****\n\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            total+=vec[i].sueldo;
        }
    }
    printf("Total sueldos a pagar $%.2f",total);
}*/

//(d)-------------------OK---------------------------------------------

void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    int hayEmpleadosEnSector = 0;
    char nombreSector[20] ;

    system("cls");
    printf("** Listado de empleados por sector **\n\n");

    listarSectores(sectores, tamsec);
    printf("\n Ingrese id del sector:");
    scanf("%d", &idSector);

    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);

    printf("\nEmpleados Sector %s \n\n ", nombreSector);

    printf("   Id       Nombre        Sexo        Edad     Sueldo     Fecha Ingreso    Sector\n");

    for (int i=0; i< tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {
            mostrarEmpleado(vec[i],sectores, tamsec);
            hayEmpleadosEnSector = 1;
        }
    }

    if ( hayEmpleadosEnSector == 0)
    {
        printf("\nNo hay empleados en el sector \n");
    }

}
//(e)----------------OK----------------------------------------------------------------------
void informarEmpleadosXSector (eEmpleado vec[], int tam, eSector sectores[], int tamsec){
int flag=0;
system("cls");
printf("****** Lista de Empleados de todos los sectores *******\n");

    for (int s= 0; s<tamsec; s++)
    {
        printf("Sector: %s\n", sectores[s].descripcion);

        for(int e=0; e<tam; e++){
            if(vec[e].isEmpty == 0 && vec[e].idSector == sectores[s].id)
            {
                mostrarEmpleado( vec[e], sectores, tamsec);
                flag =1;
            }
    }
        if (flag == 0)
        {
            printf("Sin empleados\n");
        }
}
//(f)---------------------------------------------------------------------------------------------
void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    float mayorSueldo = 0;
    int sector;
    int hayEmpleados = 0;
    char nombreSector[20];
    int flagPrimeraIteracion = 0;
    system("cls");
    printf("** Mayor sueldo por un sector **\n\n");
    listarSectores(sectores,tamsec);
    printf("\n Ingrese sector:");
    scanf("%d", &sector);

    cargarDescripcionSector(nombreSector,sector,sectores,tamsec);

    printf("\nSector %s \n\n",nombreSector);

    for (int i=0; i< tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].idSector == sector)
        {
            if (vec[i].sueldo > mayorSueldo || flagPrimeraIteracion == 0)
            {
                mayorSueldo = vec[i].sueldo;
                hayEmpleados = 1;
                flagPrimeraIteracion = 1;
            }
        }
    }

    printf("El max sueldo es: %.2f\n",mayorSueldo);

    if ( hayEmpleados == 0)
    {
        printf("\nNo hay empleados que hayan en ese sector\n");
    }
}

//(g)----------------OK---------------------------------------------------------------------------

void informarEmpleadoCostosoSector (eEmpleado vec[], int tam, eSector sectores[], int tamsec){

int idSector;
int flag =0;
int flagEmpleado = 0;
float mayorSueldo =0;
char nombreSector[20];

system("cls");
printf("Empleados que mas cobran de un sector\n");

listarSectores(sectores, tamsec);
printf("Ingrese sector: ");
scanf("%d", &idSector);

cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);

printf("Mayor sueldo sector %s \n\n", nombreSector);

for (int i=0; i<tam; i++)
    {
        if (vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {
            if(vec[i].sueldo > mayorSueldo || flag == 0)
            {
                mayorSueldo = vec[i].sueldo;
                flag = 1;
                flagEmpleado =1;
            }
        }
    }

    if(flagEmpleado == 1)
    {
        printf("Mayor sueldo sector %s es $ %.2f y lo cobran: \n\n", nombreSector, mayorSueldo);
        printf("ID	Nombre    Sexo   Edad    Sueldo    Fecha ingreso   Sector\n\n");

        for (int i=0; i<tam; i++)
        {
            if (vec[i].isEmpty == 0 && vec[i].idSector == idSector && vec[i].sueldo == mayorSueldo)
            {
                mostrarEmpleado(vec[i], sectores, tamsec);
            //printf("%s\n", vec[i].nombre);
            }
        }

    }else{
        printf("No hay empleados en el sector %s \n", nombreSector);
        }

}

//(h)-------------------------------------------------------------------------------------

void aumentarSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){

int idSector;
int porcentaje;
float aumento;
int flag =0;

system("cls");
printf("**** Aumentar sueldos de un sector ****\n");

listarSectores(sectores, tamsec);
printf("Ingrese el ID sector: \n");
scanf("%d", &idSector);

printf("Indique que porcentaje quiere aumentar: \n");
scanf("%d", &porcentaje);

for (int i=0; i<tam; i++)
{
    if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
    {
        aumento = vec[i].sueldo * porcentaje/100;
        vec[i].sueldo += aumento;
        flag=1;
    }
}
    if(flag)
    {
        printf("Se actualizaron los sueldos con exito\n");
    }else{
        printf("No hay empleados a los que actualizar sueldos\n");
    }
}

//()-------------------------------------------------------------------------

float obtenerTotalSueldosSector (int idSector, eEmpleado vec[], int tam){

float totalSueldos=0;

for (int i=0; i<tam; i++)
{
    if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
    {
        totalSueldos += vec[i].sueldo;
    }
}

return totalSueldos;
}

//(i)-----------------------------------------------------------------------------
void informarSectorCostoso (eEmpleado vec[], int tam, eSector sectores[], int tamsec){
float totalSueldos[tamsec];
float mayorTotal;
int flag =0;

system("cls");
printf("***** Sector mas costoso *****\n\n");

for(int i=0; i< tamsec; i++)
{
    totalSueldos[i] = obtenerTotalSueldosSector(sectores[i].id, vec, tam);
}

for (int i=0; i<tamsec; i++)
{
 if(totalSueldos[i] > mayorTotal || flag ==0)
 {
    mayorTotal = totalSueldos[i];
    flag =1;
 }
}
printf("El mayor gasto en sueldos es $ %.2f y se realiza en el sector: \n", mayorTotal);

for (int i=0; i<tamsec; i++){
 if( totalSueldos[i] == mayorTotal)
 {
    printf("%s\n", sectores[i].descripcion);
 }
}
}
//(j)---------------------------------------------------------------------
void informarTotalSueldos(eEmpleado vec[], int tam)
{
    float totalSueldos =0;
    system("cls");
    printf("\n*** Total de Sueldos ***\n\n");
    for(int i=0; i<tam; i++)
    {
        if (vec[i].isEmpty ==0)
        {
            totalSueldos += vec[i].sueldo;
        }

    }

    printf("El total de los sueldos es de : %.2f\n",totalSueldos);
}
//(k)----------------------------------------------------------------
void cantidadEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int cantidad;

    system("cls");
    printf("** Cantidad de empleados de todos los sector **\n\n");
   // printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso    Sector\n");

    for(int s = 0; s < tamsec; s++)
    {
        cantidad = 0;
        printf("Sector: %s\n",sectores[s].descripcion);
        for(int e = 0; e < tam; e++)
        {
            if(vec[e].isEmpty == 0 && vec[e].idSector == sectores[s].id)
            {
                cantidad++;
            }
        }
        printf("Cantidad: %d\n",cantidad);
    }
    printf("\n-----------------------------------------------------------------\n");

}
//(l)---------------------------------------------------------------------------------------
void informarEmpleadoMasJovenSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec){
	int masJoven;
	int sector;
	char nombreSector[20];
	int contador = 0;
	system("cls");
	printf("\n****** Informa Mas Joven de Sector ****** \n");
	listarSectores(sectores,tamsec);
	printf("ingrese sector");
	scanf("%d",&sector);

	cargarDescripcionSector(nombreSector, sector, sectores,tamsec);

	for (int e = 0; e<tamsec;e++){
		if (vec[e].isEmpty==0 && vec[e].idSector == sector){
			if (masJoven > vec[e].edad || contador == 0){
				masJoven = vec[e].edad;
				contador++;
			}
		}
	}
	printf("\n El mas joven del sector %10s es $ %d y pertenece a: \n",nombreSector,masJoven);
	for (int i = 0;i<tam;i++){
		if (vec[i].isEmpty==0 && vec[i].idSector == sector && vec[i].edad == masJoven){
			mostrarEmpleado(vec[i],sectores,tamsec);
		}
	}
}
}

