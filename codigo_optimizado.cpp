/**
 * @version 1.0
 * @date 10/02/2025
 * @author Juventino, Angie, Alejandro, Karla
 * @title Gestión de Productos
 * @brief Programa para gestionar productos, determinar el más caro y calcular el total de precios.
 */

#include <iostream>
using namespace std;

/**
 * @class Producto
 * @brief Clase que representa un producto con nombre y precio.
 */
class Producto {
private:
    string nombre; /**< Nombre del producto. */
    double precio; /**< Precio del producto. */
    string categoria; /**< Categoría del producto. */

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el nombre como cadena vacía, el precio en 0.0 y la categoría vacía.
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
 * @brief Solicita al usuario ingresar los datos de un producto.
 * @param producto Referencia al objeto Producto donde se almacenará la información.
 * @return void
 * @code
 * Producto p;
 * ingresarProducto(p);
 * @endcode
 */
void ingresarProducto(Producto &producto) {
    string nombre, categoria;
    double precio;

    cout << "\nIngresa el nombre del producto: ";
    cin >> ws;
    getline(cin, nombre);
    producto.setNombre(nombre);

    cout << "Ingresa la categoría del producto: ";
    getline(cin, categoria);
    producto.setCategoria(categoria);

    cout << "Ingresa el precio del producto: ";
    while (!(cin >> precio) || precio < 0) {
        cout << "Precio inválido. Ingresa un número positivo: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    producto.setPrecio(precio);
}

/**
 * @brief Determina el producto más caro y más barato ingresado hasta el momento.
 * @param productoActual Producto actual ingresado.
 * @param productoCaro Producto más caro encontrado hasta ahora.
 * @param productoBarato Producto más barato encontrado hasta ahora.
 * @param contador Número de productos ingresados.
 * @return void
 */
void determinarProductosExtremos(Producto &productoActual, Producto &productoCaro, Producto &productoBarato, int contador) {
    if (contador == 1 || productoActual.getPrecio() > productoCaro.getPrecio()) {
        productoCaro = productoActual; /**< Se actualiza el producto más caro si el precio es mayor. */
    }
    if (contador == 1 || productoActual.getPrecio() < productoBarato.getPrecio()) {
        productoBarato = productoActual; /**< Se actualiza el producto más barato si el precio es menor. */
    }
}

/**
 * @brief Muestra los resultados del producto más caro, el más barato y el total de precios.
 * @param productoCaro Producto más caro.
 * @param productoBarato Producto más barato.
 * @param totalPrecio Suma total de los precios de los productos ingresados.
 * @return void
 */
void mostrarResultados(Producto &productoCaro, Producto &productoBarato, double totalPrecio) {
    cout << "\nEl producto más caro es:\n";
    cout << "Nombre: " << productoCaro.getNombre() << endl;
    cout << "Categoría: " << productoCaro.getCategoria() << endl;
    cout << "Precio: " << productoCaro.getPrecio() << endl;

    cout << "\nEl producto más barato es:\n";
    cout << "Nombre: " << productoBarato.getNombre() << endl;
    cout << "Categoría: " << productoBarato.getCategoria() << endl;
    cout << "Precio: " << productoBarato.getPrecio() << endl;

    cout << "\nEl total de precios de todos los productos es: " << totalPrecio << endl;
}

/**
 * @brief Función principal del programa.
 * @return int Retorna 0 si la ejecución es exitosa.
 */
int main() {
    int opcion; /**< Opción del usuario para continuar ingresando productos. */
    int contador = 1; /**< Contador de productos ingresados. */
    double totalPrecio = 0.0; /**< Acumulador del total de precios. */
    
    Producto productos[100]; /**< Arreglo para almacenar los productos ingresados. */
    Producto productoActual, productoCaro, productoBarato; /**< Productos actuales, más caro y más barato. */
    
    do {
        cout << "\nProducto " << contador << endl;
        ingresarProducto(productoActual);
        totalPrecio += productoActual.getPrecio(); /**< Acumula el precio del producto actual. */
        
        productos[contador - 1] = productoActual; /**< Guarda el producto en el arreglo. */
        determinarProductosExtremos(productoActual, productoCaro, productoBarato, contador); /**< Determina el producto más caro y el más barato. */
        
        contador++;
        cout << "\n¿Quieres agregar otro producto? 1.Si 2.No: ";
        cin >> opcion;
    } while (opcion == 1); /**< Si el usuario desea continuar, se repite el ciclo. */
    
    mostrarResultados(productoCaro, productoBarato, totalPrecio); /**< Muestra los resultados finales. */
    return 0; /**< Fin del programa. */
}
