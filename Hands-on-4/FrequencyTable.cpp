#include "FrequencyTable.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void FrequencyTable::calcular(DataSet ds) {
    int* datos = ds.getData();
    n = ds.getSize();

    calcularMinMax(datos);
    calcularClases();
    crearIntervalos();
    calcularFrecuencias(datos);
    calcularRelativas();
    calcularAcumuladas();


}
 

void FrequencyTable::calcularMinMax(int datos[]){
    min = datos[0];
    max = datos[0];

    for(int i = 1; i < n; i++) {
        if(datos[i] < min) min = datos[i];
        if(datos[i] > max) max = datos[i];
    }
}
void FrequencyTable::calcularClases() {
   
    k = 1 + 3.322 * log10(n);
    if(k < 1) k = 1;
}

void FrequencyTable::crearIntervalos() {
    int R = max - min;
    int A = R / k;
    if(A == 0) A = 1;

    int limite = min;

    for(int i = 0; i < k; i++) {
        Li[i] = limite;
        Ls[i] = limite + A;
        f[i] = 0;
        limite = Ls[i] + 1;
    }
}

void FrequencyTable::calcularFrecuencias(int datos[]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(datos[i] >= Li[j] && datos[i] <= Ls[j]) {
                f[j]++;
                break;
            }
        }
    }
}

void FrequencyTable::calcularRelativas() {
    for(int i = 0; i < k; i++) {
        marca[i] = (Li[i] + Ls[i]) / 2.0;
        fr[i] = (double)f[i] / n;
        porcentaje[i] = fr[i] * 100;
    }
}

void FrequencyTable::calcularAcumuladas() {
    Fa[0] = f[0];
    Fra[0] = fr[0];

    for(int i = 1; i < k; i++) {
        Fa[i] = Fa[i-1] + f[i];
        Fra[i] = Fra[i-1] + fr[i];
    }

}

void FrequencyTable::imprimir() {
    cout << "\nTabla de Frecuencias (Agrupadas)\n";
    cout << "Clase\tLimiteClase\tf\tXc\tFa\tfr\tfra\t%\n";

    cout << fixed << setprecision(2);
    
    for(int i = 0; i < k; i++) {
        cout << i+1 << "\t"
            << Li[i] << "-" << Ls[i] << "\t\t"
            << f[i] << "\t"
            << marca[i] << "\t"
            << Fa[i] << "\t"
            << fr[i] << "\t"
            << Fra[i] << "\t"
            << porcentaje[i] << "%\n";
    }
}