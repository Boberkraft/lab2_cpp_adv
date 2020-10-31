//
// Created by MacOS on 31/10/2020.
//

#ifndef LAB2_CPP_ADV_VEKTOR3D_H
#define LAB2_CPP_ADV_VEKTOR3D_H

#include <iostream>

class Vektor3d {
    double _liczby[3];
public:
    Vektor3d(double x1, double x2, double x3) {
        _liczby[0] = x1;
        _liczby[1] = x2;
        _liczby[2] = x3;
    }

    void getCoefs(double liczby[]) {
        liczby[0] = _liczby[0];
        liczby[1] = _liczby[1];
        liczby[2] = _liczby[2];
    }

};

#endif //LAB2_CPP_ADV_VEKTOR3D_H
