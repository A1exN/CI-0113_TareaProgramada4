#include "producto.h"
#include "excepcionesProducto.h"

Producto::Producto(int id, string nombreProducto, int existencias)
{
    if (nombreProducto.length() == 0 || nombreProducto.length() > 20)
    {
        throw ExcepcionNombreProductoInvalido();
    }
    if (id <= 0)
    {
        throw ExcepcionIdentificadorProductoNoPositivo();
    }
    if (existencias < 0)
    {
        throw ExcepcionExistenciasDeProductoNegativas();
    }

    this->id = id;
    strcpy(this->nombreProducto, nombreProducto.c_str());
    this->existencias = existencias;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombreProducto, "");
    this->existencias = 0;
}

Producto::~Producto()
{

}

void Producto::ModificarNombre(string nuevoNombre)
{
    if (nuevoNombre.length() == 0 or nuevoNombre.length() > 20)
    {
        throw ExcepcionNombreProductoInvalido();
    }
    
    strcpy(this->nombreProducto, nuevoNombre.c_str());
}

void Producto::ModificarExistencias(int nuevaCantidadEnExistencia)
{
    if (nuevaCantidadEnExistencia < 0)
    {
        throw ExcepcionExistenciasDeProductoNegativas();
    }

    this->existencias = nuevaCantidadEnExistencia;
}

ostream& operator << (ostream &streamSalida, const Producto *producto)
{
    streamSalida << producto->id << ". " << producto->nombreProducto << ". En existencia: " << producto->existencias;

    return streamSalida;
}