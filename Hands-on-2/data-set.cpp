#include <iostream>
#include <iomanip>
#include "data-set.hpp"

using namespace std;

void Dataset::mostrarDatos() {
    cout << "Tabla de datos:\n";
    cout << "Advertising (x)\tSales (y)\n";

    for (int i = 0; i < SIZE; i++) {
        cout << fixed << setprecision(2) << x[i] << "\t\t" << y[i] << endl;
    }
}