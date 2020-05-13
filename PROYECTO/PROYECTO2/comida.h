
#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
typedef struct {
    int id;
    char descripcion[20];
    float precio;
}eComida;

#endif // COMIDA_H_INCLUDED

void mostrarComidas(eComida comidas[], int tam);
int cargarDescripcionComida(char descripcion[], int id, eComida comidas[], int tam);
