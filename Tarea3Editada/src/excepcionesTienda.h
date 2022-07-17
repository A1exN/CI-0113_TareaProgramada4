#ifndef EXECPCIONESTIENDA_H
#define EXECPCIONESTIENDA_H

#include "excepcionesProducto.h"
#include <exception>

class ExcepcionNombreTiendaInvalido : public std::exception
{
    public:
    ExcepcionNombreTiendaInvalido() noexcept = default;
    ~ExcepcionNombreTiendaInvalido() = default;

    virtual const char* what() const noexcept {
        return "El nombre de la tienda no puede ser nulo o exceder los 15 caracteres.";
    }
};

class ExcepcionDireccionInternetInvalida : public std::exception
{
    public:
    ExcepcionDireccionInternetInvalida() noexcept = default;
    ~ExcepcionDireccionInternetInvalida() = default;

    virtual const char* what() const noexcept {
        return "La direccion de internet no puede superar los 24 caracteres.";
    }
};

class ExcepcionDireccionFisicaInvalida : public std::exception
{
    public:
    ExcepcionDireccionFisicaInvalida() noexcept = default;
    ~ExcepcionDireccionFisicaInvalida() = default;

    virtual const char* what() const noexcept {
        return "La direccion física no puede superar los 24 caracteres.";
    }
};

class ExcepcionTelefonoTiendaInvalido : public std::exception
{
    public:
    ExcepcionTelefonoTiendaInvalido() noexcept = default;
    ~ExcepcionTelefonoTiendaInvalido() = default;

    virtual const char* what() const noexcept {
        return "El número telefónico debe estar compuesto de 8 caracteres y debe contener solo números.";
    }
};

#endif