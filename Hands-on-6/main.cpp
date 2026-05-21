#include "CalcularProbabilidades.hpp"
#include <ctime>
#include <cstdlib> 

int main() {

    srand(time(0));
    
    DataSet a;
    Calcular b;

    a.printDataset();
    b.printResults(a);

    return 0;
}