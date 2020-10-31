
#include <iostream>
using namespace std;

namespace global {
    void wypisz(double tab[], int rozmiar) {
        for (int i = 0; i < rozmiar; i++) {
            cout << tab[i] << '\t';
        }
        cout << endl;
    }
};


#include "Vektor3d.h"
#include "VektorNd.h"






int main() {
//    Vektor3d::main();
//    VektorNd::main1();
//    VektorNd::main2();
    const double wartosci[] = {1, 2, 3};
    VektorNd v1(wartosci, 3);
    ofstream file("plik.txt");
    file << &v1;
    return 0;
}