#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "infoEmpleados.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"
#include "sector.h"

//(1)-------------------------------------------------------------
int menu(){

int opcion;

system("cls");
printf("*** Gestion de Empleados ***\n");
printf("1) Alta empleado\n");
printf("2) Modificar empleado\n");
printf("3) Baja empleado\n");
printf("4) Ordenar empleados\n");
printf("5) Listar empleados\n");
printf("6) Informes\n");
printf("7) Mostrar almuerzos\n");
printf("8) Alta almuerzo\n");
printf("10) Salir\n");

printf("Ingrese opcion: \n");
fflush(stdin);
scanf("%d", &opcion);

return opcion;
}

//(2)--------------------------------------------
void mostrarEmpleados (eEmpleado vec[], int tam, eSector sectores[], int tamsec){

int flag=0;

system("cls");
printf("****** LISTA EMPLEADOS ******\n");
printf("ID	Nombre		Sexo	Edad	Sueldo		Fecha de ingreso\n");

for(int i=0; i<tam; i++){

if(vec[i].isEmpty == 0){
mostrarEmpleado(vec[i], sectores, tamsec);
flag=1;
}

if(flag==0){
printf("No hay empleados que mostrar\n");
}

}

//(3)------------------------------------------------

void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamsec)
{
	char descripcion [20];
    cargarDescripcionSector(descripcion, x.idSector, sectores, tamsec);

printf("%d 	%10s	 %c	 %d	 %6.2f	 %02d/%02d/%4d	%10s\n", x.id, x.nombre, x.sexo, x.edad, x.sueldo, x.fechaIngreso.dia, x.fechaIngreso.mes, x.fechaIngreso.anio, descripcion);
}

//(4)-----------------------------------------------------------------

void ordenarEmpleados(eEmpleado lista[], int tam){

eEmpleado auxEmpleado;

for(int i=0; i<tam-1; i++){
for(int j=i+1; j<tam; j++){
if(lista[i].sexo > lista[j].sexo)  // if(strcmp(lista[i].nombre, lista[j].nombre)>0)
{
	auxEmpleado = lista[i];
	lista[i] = lista[j];
	lista[j] = auxEmpleado;
}else if(lista[i].sexo == lista[j].sexo && lista[i].id < lista[j].id)
{
	auxEmpleado = lista[i];
	lista[i] = lista[j];
	lista[j] = auxEmpleado;
}
}//fin for j
}//fin for i
}
//(6)-------------------------------------------------------
void inicializarEmpleados(eEmpleado vec[], int tam){
for (int i=0; i<tam; i++)
{
   vec[i].isEmpty = 1;
}
}

//(7)----------------------------------------------------------------
int buscarLibre(eEmpleado vec[], int tam)
{
	int indice = -1;

	for (int i=0; i< tam; i++)
	{
 		if(vec[i].isEmpty == 1)
		{
    			indice = i;
    			break;
		}
	}
  return indice;
}
//(8)---------------------------------------------------------------------------
int buscarEmpleado(int id, eEmpleado vec[], int tam){

int indice= -1;

for(int i=0; i<tam; i++){
if(vec[i].id == id && vec[i].isEmpty ==0){
indice= i;
break;
}
}
return indice;
}
//(9)---------------------------------------------------------
int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec){

int indice= buscarLibre(vec,tam);
eEmpleado auxEmpleado;
int sumaId=0;
//int existe;

if(indice != -1)
{

printf("Ingrese nombre: \n");
fflush(stdin);
myFgets(auxEmpleado.nombre, 20);

printf("Ingrese sexo: \n");
fflush(stdin);
scanf("%c", &auxEmpleado.sexo);

printf("Ingrese edad: \n");
scanf("%d", &auxEmpleado.edad);

printf("Ingrese sueldo: \n");
scanf("%f", &auxEmpleado.sueldo);

printf("Ingrese fecha de ingreso: dd/mm/aaaa \n");
scanf("%d/%d/%d",&auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

listarSectores(sectores, tamsec);
printf("Ingrese sector.: \n");
scanf("%d", &auxEmpleado.idSector);

auxEmpleado.isEmpty = 0;
sumaId =1;
vec[indice] = auxEmpleado;

}else{
 printf("No hay espacio\n");
}
return sumaId;
}


//(11)----------------------------------------------------------
void hardcodear(eEmpleado vec[], int cant){
for (int i = 0; i<cant; i++){
 vec[i].id = ids[i];
 strcpy (vec[i].nombre, nombre[i]);
 vec[i].sexo = sexos[i];
 vec[i].edad = edades[i];
 vec[i].sueldo = sueldos[i];
 vec[i].fechaIngreso.dia = dias[i];
 vec[i].fechaIngreso.mes = meses[i];
 vec[i].fechaIngreso.anio = anio[i];
 vec[i].isEmpty = 0;
}
}


//(12)-------------------------------------------------------------------------------------------
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
//(13)----------------------------------------------------------------------------------------
int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleados[],int tam){
    int todoOk =0;
    for (int i=0; i<tam; i++)
    {
        if(empleados[i].id == id)
        {
            strcpy(nombre, empleados[i].nombre);
            todoOk=1;
        }
    }
    return todoOk;
}

//(14)-------------------------------------------------------------------

void myFgets (char nombre [], int cant)
{
    fflush (stdin);
    fgets(nombre, cant, stdin);
    nombre[strcspn(nombre, "\r\n")] = 0;
}
}


