//
// Created by MacOS on 31/10/2020.
//

#ifndef LAB2_CPP_ADV_VECTOROFVECTORS1_H
#define LAB2_CPP_ADV_VECTOROFVECTORS1_H

#include "VektorNd.h"


class VectorOfVectors1 {
    VektorNd vektory[10]{};
    int size;
public:
    VectorOfVectors1(const VektorNd *_vektory[], int _size) {
        for (int i = 0; i < _size; i++) {
            vektory[i] = *_vektory[i];
        }
        size = _size;
    }

    VectorOfVectors1(const VectorOfVectors1 &other) {
        for (int i = 0; i < other.size; i++) {
            vektory[i] = other.vektory[i];
        }
        size = other.size;
    }

    VectorOfVectors1 &operator=(const VectorOfVectors1 &right) {
        cout << "Kopia!" << endl;
        for (int i = 0; i < right.size; i++) {
            vektory[i] = right.vektory[i];
        }
        size = right.size;
        return *this;
    }

    ~VectorOfVectors1() {
        cout << "Destruktor VectorOfVectors1<" << this << ">" << endl;
    }

    friend ostream &operator<<(ostream &left, VectorOfVectors1 &right) {
        left << "VectorOfVectors1<" << &right << "> {" << endl;
        for (int i = 0; i < right.size; i++) {
            left << "  " << right.vektory[i];
        }
        left << "}" << endl;
        return left;
    }

};

#endif //LAB2_CPP_ADV_VECTOROFVECTORS1_H
