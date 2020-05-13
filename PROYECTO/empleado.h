#include "sector.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct {
 int dia;
 int mes;
 int anio;
}eFecha;

typedef struct{
 int id;
 char nombre [20];
 char sexo;
 int edad;
 float sueldo;
 eFecha fechaIngreso;
 int isEmpty;
 int idSector;
}eEmpleado;

#endif
//(1)
int menu();
//(2)
void bajaEmpleado(eEmpleado vec[], int cant,eSector sectores[], int tamsec);// falta
//(3)
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
//(4)
void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamsec);
//(5)
void ordenarEmpleados(eEmpleado lista[], int tam);
//(6)
void inicializarEmpleados(eEmpleado vec[], int tam);
//(7)
void buscarLibre(eEmpleado vec[], int tam);
//(8)
int buscarEmpleado(int id, eEmpleado vec[], int tam);
//(9)
int altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamsec);
//(10)
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec); //falta
//(11)
void hardcodear(eEmpleado vec[], int cant);
//(12)
int cargarDescripcionSector (char descripcion[], int id, eSector sectores[], int tamsec);
//(13)
int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleados[],int tam);
//(14)

void myFgets (char nombre [], int cant);

