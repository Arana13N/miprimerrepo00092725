#include <iostream>
#include <string>
using namespace std;

struct Prenda {
    string nombre;
    string talla;  // S, M, L, XL
    float precio;
    int stock;
};

// Mostrar todas las prendas disponibles
void mostrarPrendas(Prenda prendas[], int n) {
    cout << "\n--- Prendas disponibles ---\n";
    if (n == 0) {
        cout << "No hay prendas en la tienda.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << i << ". " << prendas[i].nombre 
             << " - Talla " << prendas[i].talla
             << " - $" << prendas[i].precio
             << " - Stock: " << prendas[i].stock << endl;
    }
}

// Vender una prenda (y eliminar si stock = 0)
void venderPrenda(Prenda prendas[], int &n, int indice) {
    if (indice < 0 || indice >= n) {
        cout << "Indice invalido.\n";
        return;
    }
    if (prendas[indice].stock > 0) {
        prendas[indice].stock--;
        cout << "Has vendido: " << prendas[indice].nombre << endl;

        // Si llega a 0, eliminar la prenda
        if (prendas[indice].stock == 0) {
            cout << "La prenda '" << prendas[indice].nombre 
                 << "' se eliminó porque se agotó el stock.\n";
            
            // Mover las prendas siguientes una posición hacia atrás
            for (int i = indice; i < n - 1; i++) {
                prendas[i] = prendas[i + 1];
            }
            n--; // Reducimos la cantidad de prendas
        }
    } else {
        cout << "No hay stock disponible.\n";
    }
}

int main() {
    const int MAX_PRENDAS = 50;
    Prenda prendas[MAX_PRENDAS];
    int cantidad;

    cout << "¿Cuantas prendas desea registrar? (max 50): ";
    cin >> cantidad;
    cin.ignore(); // limpiar buffer

    for (int i = 0; i < cantidad; i++) {
        cout << "\nPrenda #" << i+1 << ":\n";
        cout << "Nombre: ";
        getline(cin, prendas[i].nombre);
        cout << "Talla (S, M, L, XL): ";
        getline(cin, prendas[i].talla);
        cout << "Precio: ";
        cin >> prendas[i].precio;
        cout << "Stock: ";
        cin >> prendas[i].stock;
        cin.ignore();
    }

    mostrarPrendas(prendas, cantidad);

    int indice;
    cout << "\nIngrese el indice de la prenda a vender: ";
    cin >> indice;

    venderPrenda(prendas, cantidad, indice);

    mostrarPrendas(prendas, cantidad);

    return 0;
}