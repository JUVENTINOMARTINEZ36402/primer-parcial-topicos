/**
 * @file producto.cpp
 * @brief Programa para gestionar productos con nombre, precio y categoría.
 * 
 * Este programa permite al usuario ingresar varios productos, almacenarlos en un arreglo,
 * calcular el total de los precios, y determinar cuál es el producto más caro y el más barato.
 */

#include <iostream>
using namespace std;

/**
 * @class Producto
 * @brief Clase que representa un producto con nombre, precio y categoría.
 */
class Producto {
private:
    string nombre;    ///< Nombre del producto
    double precio;    ///< Precio del producto
    string categoria; ///< Categoría del producto

public:
    /**
     * @brief Constructor por defecto de la clase Producto.
     */
    Producto() {
        nombre = "";
        precio = 0.0;
        categoria = "";
    }

    /**
     * @brief Establece el nombre del producto.
     * @param nombre Nombre del producto.
     */
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    /**
     * @brief Obtiene el nombre del producto.
     * @return Nombre del producto.
     */
    string getNombre() {
        return nombre;
    }

    /**
     * @brief Establece el precio del producto.
     * @param precio Precio del producto.
     */
    void setPrecio(double precio) {
        this->precio = precio;
    }

    /**
     * @brief Obtiene el precio del producto.
     * @return Precio del producto.
     */
    double getPrecio() {
        return precio;
    }

    /**
     * @brief Establece la categoría del producto.
     * @param categoria Categoría del producto.
     */
    void setCategoria(string categoria) {
        this->categoria = categoria;
    }

    /**
     * @brief Obtiene la categoría del producto.
     * @return Categoría del producto.
     */
    string getCategoria() {
        return categoria;
    }
};

/**
 * @brief Función principal del programa.
 * 
 * Permite al usuario ingresar productos, determinar el más caro y el más barato,
 * y mostrar la lista de todos los productos ingresados.
 * 
 * @return 0 si el programa se ejecuta correctamente.
 */
int main() {
    int opcion, contador = 1, numProductos = 0;
    double totalPrecio = 0.0;
    Producto productos[100]; ///< Arreglo para almacenar los productos ingresados.
    Producto productoActual, productoCaro, productoBarato;

    do {
        cout << "\nProducto " << contador << endl;
        string nombre, categoria;
        double precio;

        cout << "Ingresa el nombre del producto: ";
        cin >> ws;
        getline(cin, nombre);
        productoActual.setNombre(nombre);

        cout << "Ingresa la categoría del producto: ";
        getline(cin, categoria);
        productoActual.setCategoria(categoria);

        cout << "Ingresa el precio del producto: ";
        while (!(cin >> precio) || precio < 0) {
            cout << "Precio inválido. Ingresa un número positivo: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        productoActual.setPrecio(precio);

        totalPrecio += productoActual.getPrecio();
        productos[numProductos++] = productoActual;

        if (contador == 1 || productoActual.getPrecio() > productoCaro.getPrecio()) {
            productoCaro = productoActual;
        }
        if (contador == 1 || productoActual.getPrecio() < productoBarato.getPrecio()) {
            productoBarato = productoActual;
        }

        contador++;

        cout << "\n¿Quieres agregar otro producto? 1.Si 2.No: ";
        cin >> opcion;
    } while (opcion == 1 && numProductos < 100);

    cout << "\nEl total de precios de todos los productos es: " << totalPrecio << endl;
    
    cout << "\nEl producto más caro es:\n";
    cout << "Nombre: " << productoCaro.getNombre() << endl;
    cout << "Categoría: " << productoCaro.getCategoria() << endl;
    cout << "Precio: " << productoCaro.getPrecio() << endl;
    
    cout << "\nEl producto más barato es:\n";
    cout << "Nombre: " << productoBarato.getNombre() << endl;
    cout << "Categoría: " << productoBarato.getCategoria() << endl;
    cout << "Precio: " << productoBarato.getPrecio() << endl;
    
    cout << "\nLista de todos los productos ingresados:\n";
    for (int i = 0; i < numProductos; i++) {
        cout << "Nombre: " << productos[i].getNombre() 
             << ", Categoría: " << productos[i].getCategoria() 
             << ", Precio: " << productos[i].getPrecio() << endl;
    }
    
    return 0;
}
