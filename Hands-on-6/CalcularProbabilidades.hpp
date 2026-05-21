#ifndef CALCULARPROBABILIDADES_HPP
#define CALCULARPROBABILIDADES_HPP

#include "DataSet.hpp"

class Calcular {

public:
    
    float marginalFila(DataSet& data, int fila);
    float marginalColumna(DataSet& data, int columna);

    float conjunta(DataSet& data, int fila, int columna);

    float condicional(DataSet& data, int fila, int columna);

    void printResults(DataSet& data);
};

#endif