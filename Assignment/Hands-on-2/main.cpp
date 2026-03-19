#include <iostream>
#include <iomanip>
#include "data-set.hpp"
#include "maths.hpp"

using namespace std;

int main() {

    Dataset data = {
        {1, 2, 3, 4, 5},
        {2, 4, 6, 8, 10}
    };

    int n = SIZE;

    data.mostrarDatos();
    cout << endl;

    double SX = Maths::sumX(data);
    double SY = Maths::sumY(data);
    double SXY = Maths::sumXY(data);
    double SX2 = Maths::sumX2(data);

    double b1 = (n * SXY - SX * SY) / (n * SX2 - SX * SX);
    double b0 = (SY - b1 * SX) / n;

    cout << fixed << setprecision(2);
    cout << "Ecuacion de regresion:\n";
    cout << "y = " << b0 << " + " << b1 << "x\n\n";

    double nuevosX[5] = {6, 7, 8, 9, 10};

    cout << "Predicciones:\n";
    for (int i = 0; i < 5; i++) {
        double y_pred = b0 + b1 * nuevosX[i];
        cout << "x = " << nuevosX[i] << " -> y = " << y_pred << endl;
    }

    return 0;
}