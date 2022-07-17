#include <gtest/gtest.h>
#include "./../src/tienda.h"
#include <fstream>
#include "./../src/excepcionesTienda.h"

namespace
{
    TEST(Tienda_Test, Test_Agregar_y_Obtener_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Arroz", 4);

        tienda->AgregarProducto(arroz);

        // Act - ejecute la operación
        Producto *actual = tienda->ObtenerProducto(1);
        Producto *esperado = arroz;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Eliminar_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->EliminarProducto(2);
        ostringstream streamListaProductos;
        streamListaProductos << tienda;

        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Modificar_Nombre_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->ModificarNombreProducto(2, "Atún en lata");
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n2. Atún en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Modificar_Existencias_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->ModificarExistenciasProducto(1, 150);
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 150\n2. Maíz en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Consultar_Productos)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n2. Maíz en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda();

        Producto *producto = new Producto(2, "Maíz en lata", 50);
        tiendaEsperada->AgregarProducto(producto);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaLeida = new Tienda();
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        string esperado = "Productos:\n2. Maíz en lata. En existencia: 50\n";
        string salidaPlanillaEsperada = streamSalidaTiendaEsperada.str();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(esperado, salidaPlanillaEsperada);

        string salidaPlanillaLeidaDeArchivo = streamSalidaTiendaEsperada.str();
        EXPECT_EQ(esperado, salidaPlanillaLeidaDeArchivo);
    }

    TEST(Tienda_Test, Test_Nombre_Tienda_Invalido)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal de las Tiendas", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888")
        , ExcepcionNombreTiendaInvalido);

        EXPECT_THROW(
           Tienda *tienda = new Tienda("", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888")
        , ExcepcionNombreTiendaInvalido);

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Direccion_Internet_De_Tienda_Invalida)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipaldelastiendas.com", "Avenida 2nda, local #2", "88888888")
        , ExcepcionDireccionInternetInvalida);

        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "", "Avenida 2nda, local #2", "88888888")
        , ExcepcionDireccionInternetInvalida);

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Direccion_Fisica_De_Tienda_Invalida)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Cartago Centro, Avenida 2nda, local #2", "88888888")
        , ExcepcionDireccionFisicaInvalida);

        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "", "88888888")
        , ExcepcionDireccionFisicaInvalida);

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Telefono_Tienda_Invalido)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "888")
        , ExcepcionTelefonoTiendaInvalido);

        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "888dra88")
        , ExcepcionTelefonoTiendaInvalido);

        EXPECT_THROW(
           Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888888")
        , ExcepcionTelefonoTiendaInvalido);

        // Assert - valide los resultados
    }

}