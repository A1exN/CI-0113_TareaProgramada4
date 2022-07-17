#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <vector>

using namespace std;

class Tienda
{
private:
    
    char nombreTienda[15];
    char direccionInternet[24];
    char direccionFisica[24];
    char telefono[8];
    vector<Producto*> productos;

public:

    Tienda(string nombreTienda, string direccionInternet, string direccionFisica, string telefono);
    Tienda();
    ~Tienda();

    void AgregarProducto(Producto *producto);

    Producto *ObtenerProducto(int idProducto);

    void EliminarProducto(int idProducto);

    void ModificarNombreProducto(int idProducto, string nuevoNombreProducto);

    void ModificarExistenciasProducto(int idProducto, int nuevaCantidadEnExistencia);

    void CargarDesdeStreamBinario(istream *streamEntrada);

    void GuardarEnStreamBinario(ostream *streamSalida);

    friend ostream& operator << (ostream &o, const Tienda *tienda);

};

#endif