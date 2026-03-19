#ifndef REGRESSION_H
#define REGRESSION_H

#include "data-set.hpp"

class Regression {
private:
    double b0;
    double b1;

public:
    void calcular(Dataset data);
    void mostrarEcuacion();
    double predecir(double x);
    void mostrarPredicciones(double nuevosX[], int size);
};

#endif