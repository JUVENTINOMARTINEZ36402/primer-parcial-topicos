#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
public:
    Producto() {
        nombre = "";
        precio = 0.0;
    }
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

    int main() {
    int opcion;
    int contador = 1;
    double totalPrecio = 0.0;

    Producto productoActual;
    Producto productoCaro;

    do {
        cout << "\nProducto " << contador << endl;

        string nombre;
        double precio;
        
        cout << "Ingresa el nombre del producto: ";
        cin >> ws;
        getline(cin, nombre);
        productoActual.setNombre(nombre);

        cout << "Ingresa el precio del producto: ";
        while (!(cin >> precio) || precio < 0) {
            cout << "Precio inválido. Ingresa un número positivo: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        productoActual.setPrecio(precio);

        totalPrecio += productoActual.getPrecio();