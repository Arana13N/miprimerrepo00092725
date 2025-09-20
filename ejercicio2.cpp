#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Prenda {
    string nombre;
    string talla;  // S, M, L, XL
    float precio;
    int stock;
};

// Mostrar todas las prendas disponibles
void mostrarPrendas(const vector<Prenda>& prendas) {
    cout << "\n--- Prendas disponibles ---\n";
    if (prendas.empty()) {
        cout << "No hay prendas en la tienda.\n";
        return;
    }
    for (int i = 0; i < prendas.size(); i++) {
        cout << i << ". " << prendas[i].nombre 
             << " - Talla " << prendas[i].talla
             << " - $" << prendas[i].precio
             << " - Stock: " << prendas[i].stock << endl;
    }
}

// Vender una prenda (eliminar si stock = 0)
void venderPrenda(vector<Prenda>& prendas, int indice) {
    if (indice < 0 || indice >= prendas.size()) {
        cout << "Indice invalido.\n";
        return;
    }
    if (prendas[indice].stock > 0) {
        prendas[indice].stock--;
        cout << "Has vendido: " << prendas[indice].nombre << endl;

        // Eliminar si stock llega a 0
        if (prendas[indice].stock == 0) {
            cout << "La prenda '" << prendas[indice].nombre 
                 << "' se eliminó porque se agotó el stock.\n";
            prendas.erase(prendas.begin() + indice);
        }
    } else {
        cout << "No hay stock disponible.\n";
    }
}

int main() {
    vector<Prenda> prendas;
    int cantidad;

    cout << "¿Cuantas prendas desea registrar?: ";
    cin >> cantidad;
    cin.ignore(); // limpiar buffer

    for (int i = 0; i < cantidad; i++) {
        Prenda p;
        cout << "\nPrenda #" << i+1 << ":\n";
        cout << "Nombre: ";
        getline(cin, p.nombre);
        cout << "Talla (S, M, L, XL): ";
        getline(cin, p.talla);
        cout << "Precio: ";
        cin >> p.precio;
        cout << "Stock: ";
        cin >> p.stock;
        cin.ignore();
        prendas.push_back(p);
    }

    mostrarPrendas(prendas);

    int indice;
    cout << "\nIngrese el indice de la prenda a vender: ";
    cin >> indice;

    venderPrenda(prendas, indice);

    mostrarPrendas(prendas);

    return 0;
}