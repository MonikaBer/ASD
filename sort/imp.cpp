#include <iostream>
#include "dec.h"
using namespace std;


void data ( int *t, int n ) {

    cout << "\n\nPodaj dane do tablicy\n";
    for ( int i = 0; i < n; i++ ) {
        cout << "Podaj " << i + 1 << " element tablicy:  ";
        cin >> t[i];
    }
}


void bubble_sort ( int *t, int n ) {

    int temp;
    for ( int i = n-1; i > 0; i--) {
        for ( int j = 1; j <= i; j++ ){
            if ( t[j-1] > t[j] ) {
                temp = t[j-1];
                t[j-1] = t[j];
                t[j] = temp;
            }
        }
    }
}


void insert_sort ( int *t, int n ) {

   int temp, j;
   for ( int i = 1; i < n; i++ ) {
       temp = t[i];
       j = i -1;
       while ( j > -1 ) {
         if ( temp < t[j] ) {
           t[j+1] = t[j];
         }
         else {
           t[j+1] = temp;
           j = -1;
         }
         j--;
       }
       if ( j == -1 )
        t[0] = temp;
    }
}


void select_sort ( int *t, int n ) {

    for ( int i = 0; i < n-1; i++ ) {
        int max = t[0], index = 0;
        for ( int j = 1; j < n-i; j++ ) {
            if ( max < t[j] ) {
                max = t[j];
                index = j;
            }
        }
        t[index] = t[n-i-1];
        t[n-i-1] = max;
    }
}


void print ( int *t, int n ) {
    cout << "\n\nTwoja tablica\n\n";
    for ( int i = 0; i < n; i++ ) {
        cout << t[i] << endl;
    }
}
