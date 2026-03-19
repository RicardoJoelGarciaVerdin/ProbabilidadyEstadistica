#ifndef DATASET_HPP
#define DATASET_HPP

class DataSet {
private:
    int data[35];
    int n;

public:
    DataSet();
    int* getData();
    int getSize();
    void printData();
};

#endif