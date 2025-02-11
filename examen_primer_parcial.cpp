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

    Producto productoActual;
    Producto productoCaro;
    
    productoActual.setPrecio(50.0);
    productoCaro.setPrecio(100.0);

    double totalPrecio = productoActual.getPrecio() + productoCaro.getPrecio();

    cout << "\nEl total de precios de todos los productos es: " << totalPrecio << endl;
    return 0;
}