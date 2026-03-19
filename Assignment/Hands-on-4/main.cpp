#include <iostream>
#include "DataSet.hpp"
#include "FrequencyTable.hpp"

using namespace std;

int main() {
    DataSet ds;
    ds.printData();

    FrequencyTable ft;
    ft.calcular(ds);
    ft.imprimir();

    return 0;
}