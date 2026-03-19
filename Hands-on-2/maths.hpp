#ifndef MATHS_H
#define MATHS_H

#include "data-set.hpp"

class Maths {
public:
    static double sumX(Dataset data);
    static double sumY(Dataset data);
    static double sumXY(Dataset data);
    static double sumX2(Dataset data);
};

#endif