/**
 * @version 1.0
 * @date 10/02/2025
 * @author Angie
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

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el nombre como cadena vacía y el precio en 0.0.
     */
    Producto() {
        nombre = "";
        precio = 0.0;
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
    string nombre;
    double precio;
    
    cout << "\nIngresa el nombre del producto: ";
    cin >> nombre;
    producto.setNombre(nombre);
    
    cout << "Ingresa el precio del producto: ";
    cin >> precio;
    producto.setPrecio(precio);
}

/**
 * @brief Determina el producto más caro ingresado hasta el momento.
 * @param productoActual Producto actual ingresado.
 * @param productoCaro Producto más caro encontrado hasta ahora.
 * @param contador Número de productos ingresados.
 * @return void
 */
void determinarProductoMasCaro(Producto &productoActual, Producto &productoCaro, int contador) {
    if (contador == 1 || productoActual.getPrecio() > productoCaro.getPrecio()) {
        productoCaro = productoActual;
    }
}

/**
 * @brief Muestra los resultados del producto más caro y el total de precios.
 * @param productoCaro Producto con el precio más alto.
 * @param totalPrecio Suma total de los precios de los productos ingresados.
 * @return void
 */
void mostrarResultados(Producto &productoCaro, double totalPrecio) {
    cout << "\nEl producto más caro es:\n";
    cout << "Nombre: " << productoCaro.getNombre() << endl;
    cout << "Precio: " << productoCaro.getPrecio() << endl;
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
    
    Producto productoActual;
    Producto productoCaro;
    
    do {
        cout << "\nProducto " << contador << endl;
        ingresarProducto(productoActual);
        totalPrecio += productoActual.getPrecio();
        determinarProductoMasCaro(productoActual, productoCaro, contador);
        
        contador++;
        cout << "\n¿Quieres agregar otro producto? 1.Si 2.No: ";
        cin >> opcion;
    } while (opcion == 1);
    
    mostrarResultados(productoCaro, totalPrecio);
    return 0;
}
