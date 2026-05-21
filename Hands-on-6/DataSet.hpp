#ifndef DATASET_HPP
#define DATASET_HPP

class DataSet {
private:
   
    int filas, columnas, total;
    int tabla[2][2];
    
public:
    DataSet();

    int celda(int fila, int columna);
    int Filas();
    int Columna();
    int Total();

    int sumaFila(int fila);
    int sumaColumna(int columna);

    void printDataset();
};

#endif //DATASET_HPP