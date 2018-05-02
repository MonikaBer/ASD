#include <iostream>
#include <cstring>
#include "dec.h"
using namespace std;


void data ( char *text, char *pattern ){

  cout << "Wprowadz tekst\n";
  cin.getline ( text, 100 );
  cout << "Wprowadz wzorzec\n";
  cin.getline ( pattern, 100 );
}


void naive ( char *text, char *pattern, int *result, int &quantity_of_results ){

  int quantity_of_comparisons, remembered_index_text, index_pattern = 0;
  int length_of_text, length_of_pattern;

  length_of_text = strlen (text);
  length_of_pattern = strlen (pattern);
  quantity_of_comparisons = length_of_text - length_of_pattern + 1;

  for (int index_text = 0; index_text < quantity_of_comparisons; index_text++){
    remembered_index_text = index_text;

    for ( index_pattern = 0; index_pattern < length_of_pattern;
          index_pattern++, index_text++ )
        if ( text[index_text] != pattern[index_pattern] )
            index_pattern = length_of_pattern;

    if ( index_pattern == length_of_pattern ){
        result[quantity_of_results] = remembered_index_text + 1;
        quantity_of_results++;
    }

    index_text = remembered_index_text;
  }

}


int horner ( char * t, int length_of_pattern ){

  int i = 1;
  int hash = ((int) t[0]);
  while ( i <= length_of_pattern - 1 ){
      hash = hash * 256 + ((int) t[i]);
      i++;
  }
   return hash;
}


void kr ( char *text, char *pattern, int *result, int &quantity_of_results ){

    int hash_pattern, hash_text, length_of_text, length_of_pattern, power;
    int quantity_of_comparisons, remembered_index_text, index_pattern = 0;
    int prime_number = 1000000007;
    length_of_text = strlen (text);
    length_of_pattern = strlen (pattern);
    quantity_of_comparisons = length_of_text - length_of_pattern + 1;

    hash_pattern = horner ( pattern, length_of_pattern );
    hash_pattern %= prime_number;
    hash_text = horner ( text, length_of_pattern );

    int i = 0;
    power = 1;
    while ( i < length_of_pattern-1 ){
        power *= 256;
        i++;
    }

    for ( int index_text = 0; index_text < quantity_of_comparisons;
          index_text++ ){
        if ( (hash_text % prime_number) == hash_pattern ) {
            remembered_index_text = index_text;
            for ( index_pattern = 0; index_pattern < length_of_pattern;
                  index_pattern++, index_text++ )
                if ( text[index_text] != pattern[index_pattern] )
                    index_pattern = length_of_pattern;

            if ( index_pattern == length_of_pattern ){
                result[quantity_of_results] = remembered_index_text + 1;
                quantity_of_results++;
            }
        index_text = remembered_index_text;
        }
        hash_text = (hash_text - (((int) text[index_text]) * power))
                    * 256 + ((int) text[index_text+length_of_pattern]);
    }

}


void print ( int *result, int &quantity_of_results ){

    if ( quantity_of_results != 0 ) {
      cout << "\n\nLiczba wystapien wzorca w podanym tekscie jest rowna "
      << quantity_of_results << endl;
      cout << "Wzorzec wystapil na nastepujacych pozycjach w tekscie:\n";
      for ( int i = 0; i < quantity_of_results; i++ ){
        cout << result[i] << endl;
      }
    }
    else
        cout << "Brak wystapien wzorca w tekscie\n";
}
