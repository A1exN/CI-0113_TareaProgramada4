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
        return "El identificador del producto debe ser un número entero positivo.";
    }
};

class ExcepcionExistenciasDeProductoNegativas : public std::exception
{
    public:
    ExcepcionExistenciasDeProductoNegativas() noexcept = default;
    ~ExcepcionExistenciasDeProductoNegativas() = default;

    virtual const char* what() const noexcept {
        return "Las existencias del producto deben ser un número entero positivo.";
    }
};

#endif