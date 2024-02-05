#include <iostream>
#include <vector>
#include <algorithm>
#include "Nagłówek.h"
#include <list>

using namespace std;

Zbior doubleToZbior(double wartosc) {
    Zbior nowy_zbior(4, 0.0, wartosc);
    return nowy_zbior;
}

int main()
{
    list<double> daneDoWektora = { 1.5, 5.2, 4.6, 1.2, 6.6, 7.2, 5.7, 2.7, 4.6, 0.9 };
    list<double>::iterator iter = daneDoWektora.begin();


    vector<Zbior> vec;


    while (iter != daneDoWektora.end()) {
        vec.push_back(doubleToZbior(*iter++));
    }


    for (int i = 0; i < vec.size(); i++) {
        vec[i].showDane();
        cout << endl;
    }

    Zbior testowy(4, 0.0, 1.6);
    Funktor fun(testowy);

    count_if(vec.begin(), vec.end(), fun);

}
