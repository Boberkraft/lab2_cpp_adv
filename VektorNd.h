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

    friend ostream& operator<<(ostream& left, VektorNd& right) {
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

    static void main1() {
        const double wartosci[] = {1, 2, 3};
        const double wartosci2[] = {4, 5, 6, 7, 8, 9};
        VektorNd v1(wartosci, 3);
        VektorNd v2(v1);
        VektorNd v3(wartosci2, 6);
        double l[6];
        v1.getCoefs(l);
        global::wypisz(l, 3);
        v2.getCoefs(l);
        global::wypisz(l, 3);

        v1 = v2;

        v1.getCoefs(l);
        global::wypisz(l, 3);
        v2.getCoefs(l);
        global::wypisz(l, 3);

        v1.setCoef(100.0, 0);
        v1.getCoefs(l);
        global::wypisz(l, 3);
        v2.getCoefs(l);
        global::wypisz(l, 3);

        v2 = v2;
        v2.getCoefs(l);
        global::wypisz(l, 3);
    }

    static void main2() {
        const double wartosci[] = {1, 2, 3};
        VektorNd v(wartosci, 3);
        cout << "Mój adres: " << &v << endl;
        VektorNd::wypiszV1(v);
        VektorNd::wypiszV2(v);
        cout << "hej" << endl;
    }

    static void main3() {
        const double wartosci[] = {1, 2, 3};
        VektorNd v1(wartosci, 3);
        v1.wypisz();
        VektorNd v2(v1);
        v2.wypisz();
        v2.setCoef(5, 0);
        v1.wypisz();
        v2.wypisz();
    }


};


#endif //LAB2_CPP_ADV_VEKTORND_H
