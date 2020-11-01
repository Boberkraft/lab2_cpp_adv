
#include <iostream>
#include <sstream>
using namespace std;

void wypisz(double tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i] << '\t';
    }
    cout << endl;
}


#include "Vektor3d.h"
#include "VektorNd.h"
#include "VectorOfVectors1.h"
#include "VectorOfVectors2.h"

static void main1() {
    Vektor3d v1(1, 2, 3);
    cout << sizeof v1 << endl;
    Vektor3d v2(4, 5, 6);
    Vektor3d v1Kopia1(v1);
    Vektor3d v1Kopia2 = v1;
    double l[3];
    v1.getCoefs(l);
    wypisz(l, 3);
    v2.getCoefs(l);
    wypisz(l, 3);
    v1 = v2;
    v1.getCoefs(l);
    wypisz(l, 3);
    v1Kopia1.getCoefs(l);
    wypisz(l, 3);
    v1Kopia2.getCoefs(l);
    wypisz(l, 3);
}

void main2() {
    const double wartosci[] = {1, 2, 3};
    const double wartosci2[] = {4, 5, 6, 7, 8, 9};
    VektorNd v1(wartosci, 3);
    VektorNd v2(v1);
    VektorNd v3(wartosci2, 6);
    double l[6];
    v1.getCoefs(l);
    wypisz(l, 3);
    v2.getCoefs(l);
    wypisz(l, 3);

    v1 = v2;

    v1.getCoefs(l);
    wypisz(l, 3);
    v2.getCoefs(l);
    wypisz(l, 3);

    v1.setCoef(100.0, 0);
    v1.getCoefs(l);
    wypisz(l, 3);
    v2.getCoefs(l);
    wypisz(l, 3);

    v2 = v2;
    v2.getCoefs(l);
    wypisz(l, 3);
}

void main3() {
    const double wartosci[] = {1, 2, 3};
    VektorNd v(wartosci, 3);
    cout << "Mój adres: " << &v << endl;
    VektorNd::wypiszV1(v);
    VektorNd::wypiszV2(v);
    cout << "hej" << endl;
}

void main4() {
    const double wartosci[] = {1, 2, 3};
    VektorNd v1(wartosci, 3);
    cout << v1;
    VektorNd v2(v1);
    cout << v2;
    v2.setCoef(5, 0);
    cout << v1;
    cout << v2;
}

void main5() {
    const double wartosci[] = {1, 2, 3};
    VektorNd v1(wartosci, 3);
    ofstream file("plik.txt");
    file << v1;
}

void main6() {
    const double wartosci1[] = {1, 2, 3};
    const double wartosci2[] = {4, 5, 6};
    const double wartosci3[] = {7, 8, 9, 10};

    const VektorNd *wektory[] = {
            new VektorNd(wartosci1, 3),
            new VektorNd(wartosci2, 3),
            new VektorNd(wartosci3, 4),
    };

    VectorOfVectors1 vov1(wektory, 3);
    auto vov2 = vov1;
    auto vov3 = new VectorOfVectors1(wektory, 3);

    vov1 = vov1;
    cout << vov1;

    cout << "Usuwam vov3!" << endl;
    delete vov3;
    cout << "Koniec usuwania vov3!" << endl;

}

void main7() {
    const double wartosci1[] = {1, 2, 3};
    const double wartosci2[] = {4, 5, 6};
    const double wartosci3[] = {7, 8, 9, 10};

    const VektorNd *wektory[] = {
            new VektorNd(wartosci1, 3),
            new VektorNd(wartosci2, 3),
            new VektorNd(wartosci3, 4),
    };

    VectorOfVectors2 vov1(wektory, 3);
    auto vov2 = vov1;
    auto vov3 = new VectorOfVectors2(wektory, 3);
    auto vov4 = VectorOfVectors2(*vov3);

    cout << vov1;
    cout << vov2;

    cout << "Usuwam" << endl;
    delete vov3;
    cout << "Koniec usuwania" << endl;
}

void main8() {
    VectorOfVectors2 vov;
    istringstream wejscie1("12 20.5 33\n4 508 6.3\n1\n");
    istringstream wejscie2("2 3 32 39\n1 2 3 4 5 6 7 8 9\n");

    // PROSZĘ nie zapomnieć wcisnać ENTER i wysłać EOF (cmd + D)
//    cin >> vov;
    wejscie1 >> vov;
    wejscie2 >> vov;
    cout << vov;
}

int main() {
//    main1();
//    main2();
//    main3();
//    main4();
//    main5();
//    main6();
    main7();
    main8();
}