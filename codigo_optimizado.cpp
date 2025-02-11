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

// Función principal
int main() {
    int opcion;
    int contador = 1;
    double totalPrecio = 0.0;
    
    Producto productoActual;
    Producto productoCaro;
    
    cout << "\nProducto más caro: " << productoCaro.getNombre() << " - Precio: " << productoCaro.getPrecio() << endl;
    cout << "Total de precios: " << totalPrecio << endl;

    return 0;
}