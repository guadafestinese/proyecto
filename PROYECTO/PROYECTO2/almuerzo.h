
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id;
    int idComida;
    int idEmpleado;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;
#endif //ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom);
int buscarLibreAlmuerzo (eAlmuerzo vec[], int tam);
int altaAlmuerzo(int id, eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom);

