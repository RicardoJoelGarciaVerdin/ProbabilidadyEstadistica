#include <iostream>
#include <iomanip>
#include "regression.hpp"
#include "maths.hpp"

using namespace std;

void Regression::calcular(Dataset data) {
    int n = SIZE;

    double SX = Maths::sumX(data);
    double SY = Maths::sumY(data);
    double SXY = Maths::sumXY(data);
    double SX2 = Maths::sumX2(data);

    b1 = (n * SXY - SX * SY) / (n * SX2 - SX * SX);
    b0 = (SY - b1 * SX) / n;
}

void Regression::mostrarEcuacion() {
    cout << fixed << setprecision(2);
    cout << "Ecuacion de regresion:\n";
    cout << "y = " << b0 << " + " << b1 << "x\n\n";
}

double Regression::predecir(double x) {
    return b0 + b1 * x;
}

void Regression::mostrarPredicciones(double nuevosX[], int size) {
    cout << "Predicciones:\n";
    for (int i = 0; i < size; i++) {
        cout << "x = " << nuevosX[i]
             << " -> y = " << predecir(nuevosX[i]) << endl;
    }
}