#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

/*
List contains a beginning sentinel and an end sentinel to simplify code.
At the beginning an empty list is created:
- pointer *begin indicate on beginning sentinel
- beginning sentinel indicate on end sentinel and end sentinel indicate on beginning sentinel
- pointer *end indicate on end sentinel
Elements are added between sentinels.
*/


int main(){
    struct twoway_list *list = constructor_of_empty_list();
    int choice, element, position, value;
    printf ("LISTA DWUKIERUNKOWA");

    do {
        printf ("\n\n...........................................................................................\n\n");
        printf ("[1] - dodanie elementu na podana pozycje do listy\n");
        printf ("[2] - dodanie elementu za wskazany element do listy\n");
        printf ("[3] - usuniecie elementu o podanej pozycji z listy\n");
        printf ("[4] - usuniecie elementu o podanej wartosci z listy\n");
        printf ("[5] - wyszukanie podanego elementu w liscie\n");
        printf ("[6] - wydruk listy od poczatku\n");
        printf ("[7] - wydruk listy od konca\n");
        printf ("[8] - usuniecie obecnej listy i stworzenie nowej pustej listy\n");
        printf ("[9] - koniec programu\n");
        printf ("\nTwoj wybor: ");
        scanf ("%d", &choice);
        switch (choice){
            case 1:
                printf ("Podaj element, ktory chcesz dodac: ");
                scanf ("%d", &element);
                printf ("Podaj pozycje, na ktora chcesz dodac: ");
                scanf ("%d", &position);
                push_on_position (list, element, position);
                break;
            case 2:
                printf ("Podaj element, ktory chcesz dodac: ");
                scanf ("%d", &element);
                printf ("Podaj, za ktory element w liscie ma zostac dodany element %d: ", element);
                scanf ("%d", &value);
                push_after_value (list, element, value);
                break;
            case 3:
                printf ("Podaj pozycje elementu, ktory chcesz usunac: ");
                scanf ("%d", &position);
                pop_from_position (list, position);
                break;
            case 4:
                printf ("Podaj wartosc elementu, ktory chcesz usunac: ");
                scanf ("%d", &value);
                pop_value (list, value);
                break;
            case 5:
                printf ("Podaj, jakiego elementu szukasz w liscie: ");
                scanf ("%d", &value);
                position = seek_element_in_list (list, value);
                if (position == 0)    printf ("0 - elementu %d nie ma w liscie\n", value);
                else    printf("%d - pozycja elementu %d w liscie\n", position, value);
                break;
            case 6:
                print_from_beginning (list);
                break;
            case 7:
                print_from_end (list);
                break;
            case 8:
              delete_list (list);
              list = constructor_of_empty_list();
              break;
            case 9:
              delete_list (list);
              break;
            default:
                printf("Nieprawidlowy wybor!\n");
                break;
        }
    }
    while (choice != 9);

    return 0;
}
