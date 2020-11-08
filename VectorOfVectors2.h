//
// Created by MacOS on 31/10/2020.
//

#ifndef LAB2_CPP_ADV_VECTOROFVECTORS2_H
#define LAB2_CPP_ADV_VECTOROFVECTORS2_H

#include "VektorNd.h"


class VectorOfVectors2 {
    int size{0};
    VektorNd *vektory{nullptr};
public:
    VectorOfVectors2() = default;

    VectorOfVectors2(const VektorNd *_vektory[], int _size) {
        vektory = new VektorNd[_size];
        for (int i = 0; i < _size; i++) {
            vektory[i] = *_vektory[i];
        }
        size = _size;
    }

    VectorOfVectors2(const VectorOfVectors2 &other) {
        vektory = new VektorNd[other.size];
        for (int i = 0; i < other.size; i++) {
            vektory[i] = other.vektory[i];
        }
        size = other.size;
    }

    VectorOfVectors2 &operator=(VectorOfVectors2 right) {
        swap(vektory, right.vektory);
        swap(size, right.size);
        return *this;
    }

    ~VectorOfVectors2() {
        cout << "Destruktor VectorOfVectors2<" << this << ">" << endl;
        delete [] vektory;
    }

    void dodaj_nowy(const VektorNd *vektor) {
        VektorNd *nowe_vektory = new VektorNd[size + 1];
        for (int i = 0; i < size; i++) {
            nowe_vektory[i] = vektory[i];
        }
        nowe_vektory[size] = *vektor;

        delete[] vektory;
        vektory = nowe_vektory;
        size++;
    }

    friend ostream &operator<<(ostream &left, VectorOfVectors2 &right) {
        left << "VectorOfVectors2<" << &right << "> {" << endl;
        for (int i = 0; i < right.size; i++) {
            left << "  " << right.vektory[i];
        }
        left << "}" << endl;
        return left;
    }

    friend istream &operator>>(istream &left, VectorOfVectors2 &right) {
        double liczby[10];
        size_t wymiar = 0;

        string line;
        while (getline(left, line) && !line.empty()) {
            char *p_start = (char *) line.c_str();
            char *p_end = p_start;

            while (*p_end != '\0') {
                double number = strtod(p_start, &p_end);
                p_start = p_end;
                liczby[wymiar] = number;
                wymiar++;
            }
            right.dodaj_nowy(new VektorNd(liczby, wymiar));
            wymiar = 0;
        }
        return left;
    }
};

#endif //LAB2_CPP_ADV_VECTOROFVECTORS2_H
