#include "FrequencyTable.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void FrequencyTable::calcular(DataSet ds) {
    int* datos = ds.getData();
    n = ds.getSize();

    calcularFrecuencias(datos);
    calcularRelativas();
}

void FrequencyTable::calcularFrecuencias(int datos[]){

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

void FrequencyTable::calcularRelativas() {
    for(int i = 0; i < m; i++) {
        fr[i] = (double)frecuencia[i] / n;
        porcentaje[i] = fr[i] * 100;
    }
}



void FrequencyTable::imprimir() {
    cout << "\nTabla de Frecuencias\n";
    cout << "Dato\tf\tfr\t%\n";

    cout << fixed << setprecision(2);

    for(int i = 0; i < m; i++) {
        cout << valores[i] << "\t"
             << frecuencia[i] << "\t"
             << fr[i] << "\t"
             << porcentaje[i] << "%\n";
    }
}