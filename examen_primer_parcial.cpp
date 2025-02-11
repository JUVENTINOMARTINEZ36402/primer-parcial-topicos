#include <iostream>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    string categoria;
public:
    Producto() {
        nombre = "";
        precio = 0.0;
        categoria = "";
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
    void setCategoria(string categoria) {
        this->categoria = categoria;
    }
    string getCategoria() {
        return categoria;
    }
};

int main() {
    int opcion, contador = 1, numProductos = 0;
    double totalPrecio = 0.0;
    Producto productos[100];
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
