#ifndef FREQUENCYTABLE_HPP
#define FREQUENCYTABLE_HPP

#include "DataSet.hpp"

class FrequencyTable {
private:
    int Li[20], Ls[20];
    int f[20];
    int Fa[20];
    double fr[20];
    double Fra[20];
    double marca[20];
    double porcentaje[20];

    int k;
    int n;
    int min, max;

public:
    void calcular(DataSet ds);

    void calcularMinMax(int datos[]);
    void calcularClases();
    void crearIntervalos();
    void calcularFrecuencias(int datos[]);
    void calcularRelativas();
    void calcularAcumuladas();

    void imprimir();
};

#endif