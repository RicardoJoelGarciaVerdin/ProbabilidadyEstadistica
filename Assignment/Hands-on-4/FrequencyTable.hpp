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
    double porcentaje [20];

    int k; 

public:
    void calcular(DataSet ds);
    void imprimir();
};

#endif