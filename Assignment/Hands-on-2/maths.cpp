#include "maths.hpp"

double Maths::sumX(Dataset data) {
    double total = 0;
    for (int i = 0; i < SIZE; i++)
        total += data.x[i];
    return total;
}

double Maths::sumY(Dataset data) {
    double total = 0;
    for (int i = 0; i < SIZE; i++)
        total += data.y[i];
    return total;
}

double Maths::sumXY(Dataset data) {
    double total = 0;
    for (int i = 0; i < SIZE; i++)
        total += data.x[i] * data.y[i];
    return total;
}

double Maths::sumX2(Dataset data) {
    double total = 0;
    for (int i = 0; i < SIZE; i++)
        total += data.x[i] * data.x[i];
    return total;
}