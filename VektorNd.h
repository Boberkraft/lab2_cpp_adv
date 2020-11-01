//
// Created by MacOS on 31/10/2020.
//

#ifndef LAB2_CPP_ADV_VEKTORND_H
#define LAB2_CPP_ADV_VEKTORND_H

#include <iostream>
#include <fstream>

class VektorNd {
    double *_liczby;
    int _wymiar;
private:

    void wypisz(ostream &out = cout) {
        out << "Vektor" << _wymiar << "d<" << this << ">[";
        for (int i = 0; i < _wymiar; i++) {
            out << _liczby[i];
            if (_wymiar - 1 != i)
                out << ", ";
        }
        out << "]" << endl;
    }

public:
    VektorNd() {
        _liczby = new double[0];
        _wymiar = 0;
    }

    VektorNd(const double liczby[], int wymiar) {
        cout << "konstruktor poprzez new itd." << endl;
        _liczby = new double[wymiar];
        _wymiar = wymiar;
        for (int i = 0; i < _wymiar; i++) {
            _liczby[i] = liczby[i];
        }
    }

    VektorNd(const VektorNd &oryginal) {
        cout << "konstruktor poprzez ()" << endl;
        _liczby = new double[oryginal._wymiar];
        _wymiar = oryginal._wymiar;
        for (int i = 0; i < _wymiar; i++) {
            _liczby[i] = oryginal._liczby[i];
        }
    }

    VektorNd &operator=(const VektorNd &right) {
        cout << "konstruktor poprzez =" << endl;
        if (_wymiar != right._wymiar) {
            delete[] _liczby;

            _liczby = new double[right._wymiar];
            _wymiar = right._wymiar;
        }
        for (int i = 0; i < _wymiar; i++) {
            _liczby[i] = right._liczby[i];
        }

        return *this;
    }


    ~VektorNd() {
        cout << "Zwalniam pomiec pod adresem [" << _liczby << "]" << endl;
        delete[] _liczby;
    }


    void setCoef(double wartosc, int index) {
        _liczby[index] = wartosc;
    }

    void getCoefs(double liczby[]) {
        for (int i = 0; i < _wymiar; i++) {
            liczby[i] = _liczby[i];
        }
    }

    double getCoef(int index) {
        return _liczby[index];
    }

    int getDim() {
        return _wymiar;
    }

    friend ostream &operator<<(ostream &left, VektorNd &right) {
        right.wypisz(left);
        return left;
    }

    static void wypiszV1(VektorNd v) {
        cout << "Wypisz V1:" << endl;
        cout << "    Mój adres: " << &v << endl;
        cout << "    Moje elementy: ";
        for (int i = 0; i < v.getDim(); i++) {
            cout << v.getCoef(i) << ", ";
        }
        cout << endl;
    }

    static void wypiszV2(VektorNd &v) {
        cout << "Wypisz V2:" << endl;
        cout << "    Mój adres: " << &v << endl;
        cout << "    Moje elementy: ";
        for (int i = 0; i < v.getDim(); i++) {
            cout << v.getCoef(i) << ", ";
        }
        cout << endl;
    }
};


#endif //LAB2_CPP_ADV_VEKTORND_H
