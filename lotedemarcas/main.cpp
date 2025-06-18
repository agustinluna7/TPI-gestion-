#include <iostream>
#include <string>

using namespace std;

const int CANT_MARCAS = 10;
const int CANT_PRODUCTOS = 20;

// Estructuras
struct Marca {
    int codigo;
    string nombre;
};

struct Producto {
    int codigo;
    string nombre;
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;
};

// Prototipos
void mostrarMenu();
void cargarMarcas(Marca marcas[], bool& marcasCargadas);
void cargarProductos(Producto productos[], bool marcasCargadas, Marca marcas[], bool& productosCargados);
bool existeMarca(int codigo, Marca marcas[]);

int main() {
    Marca marcas[CANT_MARCAS];
    Producto productos[CANT_PRODUCTOS];
    bool marcasCargadas = false;
    bool productosCargados = false;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarMarcas(marcas, marcasCargadas);
                break;
            case 2:
                cargarProductos(productos, marcasCargadas, marcas, productosCargados);
                break;
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Cargar Marcas\n";
    cout << "2. Cargar Productos\n";
    cout << "0. Salir\n";
    cout << "Ingrese una opcion: ";
}

void cargarMarcas(Marca marcas[], bool& marcasCargadas) {
    cout << "\n--- CARGA DE MARCAS ---\n";
    for (int i = 0; i < CANT_MARCAS; i++) {
        cout << "Marca #" << i + 1 << endl;

        cout << "Codigo (1-10): ";
        cin >> marcas[i].codigo;

        if (marcas[i].codigo < 1 || marcas[i].codigo > 10) {
            cout << "Codigo invalido. Se cancela la carga.\n";
            marcasCargadas = false;
            return;
        }

        cout << "Nombre (sin espacios): ";
        cin >> marcas[i].nombre;

        if (marcas[i].nombre == "") {
            cout << "Nombre invalido. Se cancela la carga.\n";
            marcasCargadas = false;
            return;
        }
    }

    marcasCargadas = true;
    cout << "Carga de marcas completa.\n";
}

void cargarProductos(Producto productos[], bool marcasCargadas, Marca marcas[], bool& productosCargados) {
    if (!marcasCargadas) {
        cout << "Primero debe cargar las marcas.\n";
        return;
    }

    cout << "\n--- CARGA DE PRODUCTOS ---\n";

    for (int i = 0; i < CANT_PRODUCTOS; i++) {
        cout << "Producto #" << i + 1 << endl;

        cout << "Codigo (3 digitos): ";
        cin >> productos[i].codigo;
        if (productos[i].codigo < 100 || productos[i].codigo > 999) {
            cout << "Codigo invalido. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }

        cout << "Nombre (sin espacios): ";
        cin >> productos[i].nombre;
        if (productos[i].nombre == "") {
            cout << "Nombre invalido. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }

        cout << "Precio Venta: ";
        cin >> productos[i].precioVenta;
        if (productos[i].precioVenta <= 0) {
            cout << "Precio de venta invalido. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }

        cout << "Precio Compra: ";
        cin >> productos[i].precioCompra;
        if (productos[i].precioCompra <= 0) {
            cout << "Precio de compra invalido. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }

        cout << "Stock: ";
        cin >> productos[i].stock;
        if (productos[i].stock < 0) {
            cout << "Stock invalido. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }

        cout << "Codigo de marca (1-10): ";
        cin >> productos[i].codigoMarca;
        if (!existeMarca(productos[i].codigoMarca, marcas)) {
            cout << "Codigo de marca no encontrado. Se cancela la carga.\n";
            productosCargados = false;
            return;
        }
    }

    productosCargados = true;
    cout << "Carga de productos completa.\n";
}

bool existeMarca(int codigo, Marca marcas[]) {
    for (int i = 0; i < CANT_MARCAS; i++) {
        if (marcas[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}
