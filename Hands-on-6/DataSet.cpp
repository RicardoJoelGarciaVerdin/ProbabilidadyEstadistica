#include "DataSet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

DataSet::DataSet() {
    
    // Datos randoms
   /*
    tabla[0][0] = rand() % 10 + 1;
    tabla[0][1] = rand() % 10 + 1;
    tabla[1][0] = rand() % 10 + 1;
    tabla[1][1] = rand() % 10 + 1;
    */

    //Datos definidos
    
    tabla[0][0] = 7;
    tabla[0][1] = 3;

    tabla[1][0] = 2;
    tabla[1][1] = 6;
    
    filas = 2;
    columnas = 2;

    total = 0;

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
        total += tabla [i][j];
        }   
    }
     
}

int DataSet::celda(int fila, int columna) {
    return tabla[fila][columna];
}

int DataSet::Filas() {
    return filas;
}

int DataSet::Columna() {
    return columnas;
}

int DataSet::Total(){
    return total;   
}

int DataSet::sumaFila(int fila) {
    int suma = 0;
    for (int j = 0; j < columnas; j++){
        suma += tabla[fila][j];
    }

    return suma;

}

int DataSet::sumaColumna(int columna) {
    int suma = 0;
    
    for (int i = 0; i < filas; i++){
        suma += tabla[i][columna];
    }

    return suma;
}




void DataSet::printDataset() {

    cout << "\nDataset:\n\n";

    cout << "\t";
    for (int j = 0; j < columnas; j++) {
        if (columnas == 2) cout << (j == 0 ? "Nublado\t\t" : "No Nublado\t\t");
        else cout << "C" << j << "\t\t";
    }
    cout << "Sumas\n";

    for (int i = 0; i < filas; i++) {
        if (filas == 2) cout << (i == 0 ? "Llueve\t\t" : "No llueve\t");
        else cout << "F" << i << "\t\t";

        for (int j = 0; j < columnas; j++) cout << tabla[i][j] << "\t\t";
        cout << sumaFila(i) << "\n";
    }

    cout << "Sumas\t\t";
    for (int j = 0; j < columnas; j++) cout << sumaColumna(j) << "\t\t";
    cout << total << "\n";
}