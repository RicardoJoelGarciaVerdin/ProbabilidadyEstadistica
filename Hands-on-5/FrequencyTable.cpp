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
   
    k = ceil (1 + 3.322 * log10(n));
    if(k < 1) k = 1;
}

void FrequencyTable::crearIntervalos() {

    int A = ceil((double)(max - min + 1) / k);

    int limite = min;

    for(int i = 0; i < k; i++) {

        Li[i] = limite;
        Ls[i] = limite + A - 1;

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

double FrequencyTable::calcularMedia(){
    double suma = 0;

    for (int i = 0; i < k; i++)  {
        suma += f[i] * marca[i];
    }
    
    return suma / n;
}

double FrequencyTable::calcularModa(){
    int pos = 0;

    for(int i = 1; i < k; i++) {
        if(f[i] > f[pos]) {
            pos = i;
        }
    }

    int fm = f[pos];
    int f1 = (pos == 0) ? 0 : f[pos-1];
    int f2 = (pos == k-1) ? 0 : f[pos+1];

    int A = (Ls[0] - Li[0]) + 1;

    return (Li[pos] - 0.5) + ((double)(fm - f1) / ((fm - f1)+(fm - f2))) * A;
}

double FrequencyTable::calcularMediana(){
    int mitad = n / 2;
    int pos = 0;

    for(int i = 0; i < k; i++) {
        if(Fa[i] >= mitad) {
            pos = i;
            break;
        }
    }

    int FaAnterior = (pos == 0) ? 0 : Fa[pos-1];

    int A = (Ls[0] - Li[0]) + 1;

    return (Li[pos] - 0.5) + ((double)(mitad - FaAnterior) / f[pos]) * A;
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

    cout << "\nMedia: " << calcularMedia() << endl;
    cout << "Moda: " << calcularModa() << endl;
    cout << "Mediana: " << calcularMediana() << endl;
}