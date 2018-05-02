#include <iostream>
#include "dec.h"
using namespace std;


int main() {
    int n, c;

    cout << "Prosze podac ilosc elementow tablicy\n";
    cin >> n;
    while ( n <=0 ) {
        cout << "\nPodales niedodatnia liczbe elementow.";
        cout << " Podaj liczbe elementow jeszcze raz\n";
        cin >> n;
    }

    int t[n];

    cout << "[1] - podanie danych\n[2] - bubble sort\n[3] - insert sort\n";
    cout << "[4] - select sort\n[5] - wydruk tablicy\n";
    cout << "[6] - koniec programu\n\n";
    cin >> c;

    while ( c != 6 ) {

        if ( c == 1 )
            data ( t, n );
        else if ( c == 2 )
            bubble_sort ( t, n );
        else if ( c == 3 )
            insert_sort ( t, n );
        else if ( c == 4 )
            select_sort ( t, n );
        else if ( c == 5 )
            print ( t, n );
        else
            cout << "Niewlasciwy wybor. Wybierz jeszcze raz\n\n";

        cout << "[1] - podanie danych\n[2] - bubble sort\n[3] - insert sort\n";
        cout << "[4] - select sort\n[5] - wydruk tablicy\n";
        cout << "[6] - koniec programu\n\n";
        cin >> c;
        cout << "\nTwoj wybor: " << c << "\n\n";
    }

    return 0;
}
