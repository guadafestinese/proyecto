#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED
typedef struct{
    int id;
    char descripcion [20];
}eSector;

#endif // SECTOR_H_INCLUDED

void listarSectores(eSector sectores[], int tamSector);
int cargarDescripcionSector (char descripcion[], int id, eSector sectores[], int tamsec);

