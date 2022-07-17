FLAGS = -g -fPIC -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ -shared -o bin/libtienda.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/producto.h ./bin/include
	cp src/tienda.h ./bin/include
	cp src/excepcionesProducto.h ./bin/include
	cp src/excepcionesTienda.h ./bin/include
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/producto_tests.cpp -o obj/producto_tests.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o obj/tienda_tests.o
	g++ -g -o bin/tests obj/producto.o obj/producto_tests.o obj/tienda.o obj/tienda_tests.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj
	rm -Rf archivo_test.dat