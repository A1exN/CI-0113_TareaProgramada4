# Tarea Programada 3

Biblioteca que permite administrar las existencias de los productos de una tienda. La funcionalidad es la siguiente:

1. Permite guardar y consultar la información general de la tienda, incluyendo:
    - Nombre de la tienda (string de 15 caracteres)
    - Dirección de intenet (string de 24 caracteres)
    - Dirección física (string de 24 caracteres)
    - Teléfono (string de 8 caracteres)

2. Permite agregar productos a la tienda. Cada producto tiene la siguiente información:
    - ID del producto (número entero)
    - Nombre del producto (string de 20 caracteres)
    - Número de existencias en la tienda (número entero)

3. Permite guardar en un archivo binario toda la información de la tienda.
4. Permite cargar toda la información desde un archivo binario.

La estructura de un producto es la siguiente:

<center>

|    Campo    | Offset | Bytes |
| ----------- |:------:|:-----:|
| ID          | 0      | 4     |
| Nombre      | 4      | 20    |
| Existencias | 24     | 4     |
| Total Bytes |        | 28    |

</center>

La estructura de una tienda es la siguiente:

<center>

|       Campo       | Offset |   Bytes   |
| ----------------- |:------:|:---------:|
| Nombre            | 0      | 15        |
| Direccion Intenet | 15     | 24        |
| Dieccion Física   | 39     | 24        |
| Teléfono          | 63     |  8        |
| Productos         | 71     | 28*$n$    |
| Total Bytes       |        | 71+28*$n$ |

</center>

En donde $n$ es la cantidad de productos en la tienda.

## Compilación

Para compilar la biblioteca ejecute:
```
make
```

Para eliminar las carpetas y archivos generados ejecute:
```
make clean
```
## Pruebas unitarias

Para correr las pruebas unitarias ejecute:
```
make test
```
```
./bin/tests
```