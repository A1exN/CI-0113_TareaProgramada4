#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Producto
{
private:
    
    int id;
    char nombreProducto[20];
    int existencias;

public:
    Producto(int id, string nombreProducto, int existencias);
    Producto();
    ~Producto();

    void ModificarNombre(string nuevoNombre);

    void ModificarExistencias(int nuevaCantidadEnExistencia);

    friend ostream& operator << (ostream &streamSalida, const Producto *producto);
};

#endif