#include "CalcularProbabilidades.hpp"
#include <iostream>

using namespace std;

float Calcular::marginalFila(DataSet& data, int fila) {
    return (float)data.sumaFila(fila) / data.Total();
}

float Calcular::marginalColumna(DataSet& data, int columna) {
    return (float)data.sumaColumna(columna) / data.Total();
}

float Calcular::conjunta(DataSet& data, int fila, int columna) {
    return (float)data.celda(fila, columna) / data.Total();
}

float Calcular::condicional(DataSet& data, int fila, int columna) {
    float denom = data.sumaColumna(columna);
    if (denom == 0) return 0;
    return (float)data.celda(fila, columna) / denom;
}

void Calcular::printResults(DataSet& data) {
    cout << "\n--------------";
    cout << "\nProbabilidades\n";

    cout<< "\nMarginal";
    cout << "\nMarginal Columna Nublado: " << marginalColumna(data, 0);
    cout << "\nMarginal Columna No Nublado: " << marginalColumna(data, 1);
    cout << "\nMarginal Fila Llueve: " << marginalFila(data, 0);
    cout << "\nMarginal Fila No llueve: " << marginalFila(data, 1);
    cout << endl;

    cout << "\nCondicional";
    cout << "\nCondicional (Nublado, Llueve): " << condicional(data, 0, 0);
    cout << "\nCondicional (Nublado, No llueve): " << condicional(data, 1, 0);
    cout << "\nCondicional (No Nublado, Llueve): " << condicional(data, 0, 1);
    cout << "\nCondicional (No Nublado, No llueve):  " << condicional(data, 1, 1);
    cout << endl;

    cout << "\nConjunta";
    cout << "\nConjunta (Nublado, Llueve): " << conjunta(data, 0, 0);
    cout << "\nConjunta (Nublado, No llueve): " << conjunta(data, 1, 0);
    cout << "\nConjunta (No Nublado, Llueve): " << conjunta(data, 0,1);
    cout << "\nConjunta (No Nublado, No llueve): " << conjunta(data, 1, 1);    
    cout << endl;
}