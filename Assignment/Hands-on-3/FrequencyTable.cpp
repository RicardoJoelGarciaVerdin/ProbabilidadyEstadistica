#include "FrequencyTable.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void FrequencyTable::calcular(DataSet ds) {
    int* datos = ds.getData();
    int n = ds.getSize();

    m = 0;

    for(int i = 0; i < n; i++) {
        bool existe = false;

        for(int j = 0; j < m; j++) {
            if(datos[i] == valores[j]) {
                frecuencia[j]++;
                existe = true;
                break;
            }
        }

        if(!existe) {
            valores[m] = datos[i];
            frecuencia[m] = 1;
            m++;
        }
    }
}

void FrequencyTable::imprimir() {
    int total = 0;

    for(int i = 0; i < m; i++) {
        total += frecuencia[i];
    }

    cout << "\nTabla de Frecuencias\n";
    cout << "Dato\tf\tfr\t%\n";

    for(int i = 0; i < m; i++) {
        double fr = (double)frecuencia[i] / total;
        double porcentaje = fr * 100;

        cout<< fixed << setprecision(2);
        
        cout << valores[i] << "\t"
             << frecuencia[i] << "\t"
             << fr << "\t"
             << porcentaje << "%\n";
    }
}