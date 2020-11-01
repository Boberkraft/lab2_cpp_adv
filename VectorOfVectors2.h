//
// Created by MacOS on 31/10/2020.
//

#ifndef LAB2_CPP_ADV_VECTOROFVECTORS2_H
#define LAB2_CPP_ADV_VECTOROFVECTORS2_H

#include "VektorNd.h"


class VectorOfVectors2 {
    VektorNd *vektory { nullptr };
    int size { 0 };
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

    VectorOfVectors2 &operator=(const VectorOfVectors2 &right) {

        if (size != right.size) {
            delete[] vektory;
            vektory = new VektorNd[right.size];
            size = right.size;
        }
        for (int i = 0; i < size; i++) {
            vektory[i] = right.vektory[i];
        }
        return *this;
    }

    ~VectorOfVectors2() {
        cout << "Destruktor VectorOfVectors2<" << this << ">" << endl;
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
        cout << "wczytuję..." << endl;
        string line;
        while (getline(left, line)) {
            int start = 0;
            for (int i = 0; i < line.size() + 1; i++) {
                bool end_of_line = (i == line.size());
                if (end_of_line || line[i] == ' ') {
                    string tmp = line.substr(start, i - start);
                    double number;
                    number = strtod(tmp.c_str(), nullptr);
                    cout << number << endl;
                    start = i + 1;
                }

            }
            cout << line << endl;
        }
        return left;
    }
};

#endif //LAB2_CPP_ADV_VECTOROFVECTORS2_H
