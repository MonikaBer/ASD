#include "dec.h"

int linear_seek ( int *t, int n, int a ) {

  for ( int i = 0; i < n; i++ )
    if ( t[i] == a )
      return i;

  return -1;
}


int binary_i_seek ( int *t, int n, int a ) {

  int p = n, l = 0, index;
  while ( p - l > 1 ) {
    index = (l + p) / 2;
    if ( t[index] == a )
      return index;
    else if ( a < t[index] )
      p = index;
    else
      l = index+1;
  }

  if ( a == t[l] )
    return l;

  return -1;
}


int binary_r_seek ( int *t, int left, int right, int a ) {

      int index;

      if ( right - left > 1 ) {
          index = (left + right) / 2;
      	  if ( t[index] == a )
              return index;
          else if ( a < t[index] )
              return binary_r_seek ( t, left, index, a );
          else
              return binary_r_seek ( t, index+1, right, a );
      }
      else
          if ( a == t[left] )
              return left;

  return -1;
  }


int binary_r_helper ( int *t, int n, int a ) {

  int left = 0, right = n;

  return binary_r_seek ( t, left, right, a );

}
