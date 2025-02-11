#include <iostream>
using namespace std;

// Clase Producto
class Producto {
private:
    string nombre;
    double precio;
public:
    // Constructor
    Producto() {
        nombre = "";
        precio = 0.0;
    }
    // Setters y Getters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    string getNombre() {
        return nombre;
    }
    void setPrecio(double precio) {
        this->precio = precio;
    }
    double getPrecio() {
        return precio;
    }
};


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

// Función para determinar el producto más caro
void determinarProductoMasCaro(Producto &productoActual, Producto &productoCaro, int contador) {
    if (contador == 1 || productoActual.getPrecio() > productoCaro.getPrecio()) {
        productoCaro = productoActual;
    }
}

// Función para mostrar resultados
void mostrarResultados(Producto &productoCaro, double totalPrecio) {
    cout << "\nEl producto más caro es:\n";
    cout << "Nombre: " << productoCaro.getNombre() << endl;
    cout << "Precio: " << productoCaro.getPrecio() << endl;
    cout << "\nEl total de precios de todos los productos es: " << totalPrecio << endl;
}

// Función principal
int main() {
    int opcion;
    int contador = 1;
    double totalPrecio = 0.0;
    
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