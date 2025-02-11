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

