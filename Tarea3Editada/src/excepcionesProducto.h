#ifndef ExcepcionesProducto_H
#define ExcepcionesProducto_H

#include <exception>

class ExcepcionNombreProductoInvalido : public std::exception
{
    public:
    ExcepcionNombreProductoInvalido() noexcept = default;
    ~ExcepcionNombreProductoInvalido() = default;

    virtual const char* what() const noexcept {
        return "El nombre del producto no puede ser nulo o exceder los 20 caracteres.";
    }
};

class ExcepcionIdentificadorProductoNoPositivo : public std::exception
{
    public:
    ExcepcionIdentificadorProductoNoPositivo() noexcept = default;
    ~ExcepcionIdentificadorProductoNoPositivo() = default;

    virtual const char* what() const noexcept {
        return "El identificador del producto no puede ser negativo.";
    }
};

class ExcepcionExistenciasDeProductoNegativas : public std::exception
{
    public:
    ExcepcionExistenciasDeProductoNegativas() noexcept = default;
    ~ExcepcionExistenciasDeProductoNegativas() = default;

    virtual const char* what() const noexcept {
        return "Las existencias del producto no pueden ser negativas.";
    }
};

#endif