#include <iostream>
#include "dec.h"
using namespace std;


int main()     //result is an index of the last even number in array t[n]
{
    int n, r, result, beginning_of_final_range;
    cout << "Podaj ilosc liczb calkowitych:\n";
    cin >> n;
    while ( n <= 0 ){
        cout << "Podales niedodatnia ilosc liczb.";
        cout<< " Podaj ilosc liczb jeszcze raz:\n";
        cin >> n;
    }

    int t[n];

    data ( t, n, r );

    result = sort01 ( t, n );

    initialization_and_quick_sort_call ( t, result );

    beginning_of_final_range = find_range ( t, result, r );

    print ( beginning_of_final_range, r );
    return 0;
}
