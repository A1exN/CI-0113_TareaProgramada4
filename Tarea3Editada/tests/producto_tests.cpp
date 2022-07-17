#include <gtest/gtest.h>
#include "./../src/producto.h"
#include "./../src/excepcionesProducto.h"

namespace
{
    TEST(Producto_Test, Test_Modificar_Nombre_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "Bolsas de Arroz", 200);

        // Act - ejecute la operación
        producto->ModificarNombre("Latas de Maíz");
        ostringstream streamSalida {};
        streamSalida << producto;

        string actual = streamSalida.str();
        string esperado = "1. Latas de Maíz. En existencia: 200";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Modificar_Existencias_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "Bolsas de Arroz", 200);

        // Act - ejecute la operación
        producto->ModificarExistencias(150);
        ostringstream streamSalida {};
        streamSalida << producto;
        
        string actual = streamSalida.str();
        string esperado = "1. Bolsas de Arroz. En existencia: 150";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Consulta_Productos)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(2, "Arroz", 4);
        ostringstream streamSalida {};
        streamSalida << producto;

        // Act - ejecute la operación
        string actual = streamSalida.str();
        string esperado = "2. Arroz. En existencia: 4";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Identificador_De_Producto_No_Positivo)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación

        EXPECT_THROW(
           Producto *producto = new Producto(0, "Bolsas de Arroz", 4)
        , ExcepcionIdentificadorProductoNoPositivo);

        EXPECT_THROW(
           Producto *producto = new Producto(-2, "Bolsas de Arroz", 4)
        , ExcepcionIdentificadorProductoNoPositivo);

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Nombre_De_Producto_Invalido)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(2, "Bolsas de Arroz", 4);

        // Act - ejecute la operación

        EXPECT_THROW(
            producto->ModificarNombre("");
        , ExcepcionNombreProductoInvalido);

        EXPECT_THROW(
            producto->ModificarNombre("Nombre de 20 caracteres o mas");
        , ExcepcionNombreProductoInvalido);

        delete producto;

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Existencias_De_Producto_Negativas)
    {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación

        EXPECT_THROW(
           Producto *producto = new Producto(2, "Bolsas de Arroz", -3)
        , ExcepcionExistenciasDeProductoNegativas);

        // Assert - valide los resultados
    }

}