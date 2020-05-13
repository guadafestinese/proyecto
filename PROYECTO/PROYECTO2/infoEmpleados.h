#include "empleado.h"
//(1)----------------------------------------------------------------------------------------
void informeEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
//(2)-------------------------------------------------------------------------------------------
char menuInformes();
//(a)-------------------------------------------------------------------------------------------
void listarEmpleadosPorAnio(eEmpleado vec[], int tam,eSector sectores[], int tamsec);

//(b)-------------------------------------------------------------------------------------------
void listarEmpleadas(eEmpleado vec[], int tam,eSector sectores[], int tamsec);

//(c)-------------------------------------------------------------------------------------------
//void informarTotalSueldosSector(eEmpleado vec[], int tam,eSector sectores[], int tamsec);

//(d)-------------------------------------------------------------------------------------------
void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(e)-------------------------------------------------------------------------------------------
void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(f)-------------------------------------------------------------------------------------------
void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(g)-------------------------------------------------------------------------------------------
void informarEmpleadoCostosoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(h)-------------------------------------------------------------------------------------------
void aumentarSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(i)-------------------------------------------------------------------------------------------
void informarSectorCostoso(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

//(j)-------------------------------------------------------------------------------------------
void informarTotalSueldos(eEmpleado vec[], int tam);
float obtenerTotalSueldosSector (int idSector, eEmpleado vec[], int tam);

//(k)------------------------------------------------------------------------------
void cantidadEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
//-------------------------------------------------------------------------------------------
void informarTotalSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
//(l)-------------------------------------------------------------------------------------------
void informarEmpleadoMasJovenSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec);


