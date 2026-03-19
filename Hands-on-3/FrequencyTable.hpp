#ifndef FREQUENCYTABLE_HPP
#define FREQUENCYTABLE_HPP

#include "DataSet.hpp"

class FrequencyTable {
private:
    int valores[20];
    int frecuencia[20];
    double fr[20];
    double porcentaje [20];    
    int m;
    int n; 

public:
    void calcular(DataSet ds);
    
    void calcularFrecuencias(int datos[]);
    void calcularRelativas();

    void imprimir();
};

#endif