#include "DataSet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

DataSet::DataSet() {
    
    n = 30;

    srand(time(0));

    for(int i = 0; i < n; i++) {
        data[i] = rand() % 30 + 1 ;
    }
}

int* DataSet::getData() {
    return data;
}

int DataSet::getSize() {
    return n;
}

void DataSet::printData() {
    cout << "\nDatos: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}