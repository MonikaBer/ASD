#include <iostream>
#include <algorithm>
#include "dec.h"
using namespace std;


void data ( point *points, int n ){

  cout << "Podawaj wspolrzedne (x, y) punktow w ukladzie wspolrzednych\n";
  for ( int i = 0; i < n; i++ ){
    cout << "\n\nPodaj wsporzedna x " << i + 1 << " punktu\n";
    cin >> points[i].x;
    cout << "\nPodaj wsporzedna y " << i + 1 << " punktu\n";
    cin >> points[i].y;
  }
}


void sort012 ( point *points, int n, int &in1, int &in2, int &in3 ){

  while ( in2 < in3 ){
    if ( points[in2].x == 0 || points[in2].y == 0 ){   //osie ("0")
      swap ( points[in1], points[in2] );
      ++in1;
      ++in2;
    }
    else if ( (points[in2].x < 0 && points[in2].y > 0) || (points[in2].x > 0 && points[in2].y < 0) )   //2 lub 4 ćwiartka ("1")
      ++in2;
    else   //1 lub 3 ćwiartka ("2")
      swap ( points[in2], points[--in3] );
  }
}


void print ( point *points, int n, int &in1, int &in2, int &in3){

  if ( in1 > 0 ){
    cout << "\n\nPunkty lezace na osiach ukladu:\n";
    for ( int i = 0; i < in1; i++ ){
      cout << "( " << points[i].x << ", " << points[i].y << " )\n";
    }
  }

  if ( in1 != in3 ){
    cout << "Punkty lezace w cwiartkach 2 lub 4:\n";
    for ( int i =  in1; i < in3; i++ ){
      cout << "( " << points[i].x << ", " << points[i].y << " )\n";
    }
  }

  if ( in3 < n ){
    cout << "Punkty lezace w cwiartkach 1 lub 3:\n";
    for ( int i = in3; i < n; i++ ){
      cout << "( " << points[i].x << ", " << points[i].y << " )\n";
    }
  }
}
