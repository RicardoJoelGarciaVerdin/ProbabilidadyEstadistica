#include <iostream>
#include "data-set.hpp"
#include "regression.hpp"

using namespace std;

int main() {

    Dataset data = {
        {1, 2, 3, 4, 5},
        {2, 4, 6, 8, 10}
    };

    data.mostrarDatos();
    cout << endl;

    Regression r;

    r.calcular(data);
    r.mostrarEcuacion();

    double nuevosX[5] = {6, 7, 8, 9, 10};
    r.mostrarPredicciones(nuevosX, 5);

    return 0;
}