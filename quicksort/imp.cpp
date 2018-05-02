#include <iostream>
#include <algorithm>
#include "dec.h"
using namespace std;


void data ( int *t, int n, int &r ){

    cout << "\n\nPodawaj liczby calkowite:\n";
    for ( int i = 0; i < n; i++ ){
        cout << "\nPodaj " << i + 1 << " liczbe\n";
        cin >> t[i];
    }
    cout << "\nPodaj dlugosc przedzialu:\n";
    cin >> r;
    while ( r <= 0 ){
        cout << "\nPodales niedodatnia dlugosc przedzialu.";
        cout << "\nPodaj dlugosc przedzialu jeszcze raz:\n";
        cin >> r;
    }
}


//function sort01 divide array into even and odd numbers
int sort01 ( int *t, int n ){  //function return index of the last even number

    int left = 0, right = n - 1;

    while ( left < right ){
        while ( t[left] % 2 == 0 )
          left++;
        while ( t[right] % 2 != 0 )
          right--;
        if ( left < right )
          swap ( t[left++], t[right--] );

    }
    if ( t[right] % 2 != 0 )
        return right - 1;
    return right;
}


//function partition divide array according to value of pivot
int partition ( int *t, int left, int right ){

    int pivot = t[left], i = left+1, j = right;
    while ( i < j ){
        while ( t[i] <= pivot && i < j )
          i++;
        while ( t[j] > pivot && i < j )
          j--;
        if ( i < j ) {
            swap ( t[i++], t[j--] );
        }
    }
    if ( t[i] <= pivot ){
        swap ( t[left], t[i] );
    }
    else {
      i--;
      if ( i != left )
        swap ( t[i], t[left] );
    }

    return i;     //function return index of pivot
}


//sorting of even numbers (left part of the array)
void quick_sort ( int *t, int left, int right ){
    int index_of_border; //border between two ranges (index of the previous pivot)
    if ( left < right ){
        index_of_border = partition ( t, left, right );
        quick_sort ( t, left, index_of_border - 1 );
        quick_sort ( t, index_of_border + 1, right );
    }
}


void initialization_and_quick_sort_call ( int  *t, int result ){

    int left = 0, right = result;
    quick_sort ( t, left, right );

}


//searching of the range which contains the most even numbers
int find_range ( int *t, int result, int r ){
//ii is an initial value of i on the beginning of searching the current range
  int max = 0, quantity, i = 0, ii = 0, beginning_of_final_range = t[0];
  int start = t[0], end, st = start;
//st is the initial value of start (for the current range)
//i is an index of the nearest even number in array
  while ( start <= t[result] ) {
//start and end are properly the beginning and the end of the current range
    if ( start > t[ii] ){
      i = ii + 1;
      ii++;
    }
    else
      i = ii;
    end = start + r;
    quantity = 0;   //amount of even numbers in the current range
    while ( start <= end ) {

      if ( start == t[i] && start <= t[result] ) {
        i++;
        quantity++;
      }
      if ( start != t[i] || start > t[result] )
        start += 2;
    }
    if ( quantity > max ) {
      max = quantity;  //max is the most amount of even numbers in range
      beginning_of_final_range = st;
    }
    st += 2;
    start = st;
  }

  return beginning_of_final_range;
}


void print ( int beginning_of_final_range, int r ){

  cout << "Na podstawie podanych liczb przedzialem dlugosci " << r;
  cout << " o najwiecej ilosci liczb parzystych jest przedzial < ";
  cout << beginning_of_final_range << ", ";
  cout << beginning_of_final_range + r << " >\n";
}
