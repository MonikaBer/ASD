#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int main(){
    struct oneway_list *list = constructor_of_empty_list();
    int choice, element, position, value;
    printf ("LISTA JEDNOKIERUNKOWA ACYKLICZNA");
    do {
        printf ("\n\n...........................................................................................\n\n");
        printf ("[1] - dodanie elementu na podana pozycje do listy\n");
        printf ("[2] - dodanie elementu za wskazany element do listy\n");
        printf ("[3] - usuniecie elementu o podanej pozycji z listy\n");
        printf ("[4] - usuniecie elementu o podanej wartosci z listy\n");
        printf ("[5] - wyszukanie podanego elementu w liscie\n");
        printf ("[6] - wydruk listy od poczatku\n");
        printf ("[7] - usuniecie obecnej listy i stworzenie nowej pustej listy\n");
        printf ("[8] - koniec programu\n");
        printf ("\nTwoj wybor: ");
        scanf ("%d", &choice);
        switch (choice){
            case 1:
                printf ("Podaj dodawany element: ");
                scanf ("%d", &element);
                printf ("Podaj pozycje, na ktora chcesz dodac: ");
                scanf ("%d", &position);
                list = push_on_position (list, element, position);
                break;
            case 2:
                printf ("Podaj dodawany element: ");
                scanf ("%d", &element);
                printf ("Podaj, za ktory element chcesz dodac: ");
                scanf ("%d", &value);
                list = push_after_value (list, element, value);
                break;
            case 3:
                printf ("Podaj pozycje usuwanego elementu: ");
                scanf ("%d", &position);
                list = pop_from_position (list, position);
                break;
            case 4:
                printf ("Podaj wartosc usuwanego elementu: ");
                scanf ("%d", &value);
                list = pop_value (list, value);
                break;
            case 5:
                printf ("Podaj szukany element: ");
                scanf ("%d", &value);
                position = seek_element_in_list (list, value);
                if (position == 0)    printf ("0 - ELEMENTU %d NIE MA W LISCIE\n", value);
                else    printf ("%d - POZYCJA ELEMENTU %d W LISCIE\n", position, value);
                break;
            case 6:
                print_from_beginning (list);
                break;
            case 7:
              delete_list (list);
              list = constructor_of_empty_list();
              break;
            case 8:
              delete_list (list);
              break;
            default:
                printf("Nieprawidlowy wybor!\n");
                break;
        }
    }
    while (choice != 8);

    return 0;
}
