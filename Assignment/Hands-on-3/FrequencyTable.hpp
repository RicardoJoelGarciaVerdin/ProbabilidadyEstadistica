#ifndef FREQUENCYTABLE_HPP
#define FREQUENCYTABLE_HPP

#include "DataSet.hpp"

class FrequencyTable {
private:
    int valores[20];
    int frecuencia[20];
    int m; // cantidad de valores distintos

public:
    void calcular(DataSet ds);
    void imprimir();
};

#endif