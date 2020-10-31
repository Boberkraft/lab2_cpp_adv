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

    static void main() {
        Vektor3d v1(1, 2, 3);
        cout << sizeof v1 << endl;
        Vektor3d v2(4, 5, 6);
        Vektor3d v1Kopia1(v1);
        Vektor3d v1Kopia2 = v1;
        double l[3];
        v1.getCoefs(l);
        global::wypisz(l, 3);
        v2.getCoefs(l);
        global::wypisz(l, 3);
        v1 = v2;
        v1.getCoefs(l);
        global::wypisz(l, 3);
        v1Kopia1.getCoefs(l);
        global::wypisz(l, 3);
        v1Kopia2.getCoefs(l);
        global::wypisz(l, 3);
    }
};

#endif //LAB2_CPP_ADV_VEKTOR3D_H
