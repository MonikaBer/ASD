#include <stdio.h>
#include <stdlib.h>
#include "dec.h"


int main()
{
    Tree tree;
    tree.root = NULL;
    struct node *temp = NULL;
    int choice, value;
    printf ("\nDrzewo BST\n\n");
    do {
        printf ( ".....................................................................\n" );
        printf ("[1] - dodanie elementu do drzewa\n");
        printf ("[2] - przeglad drzewa inorder\n");
        printf ("[3] - wyszukanie elementu w drzewie\n");
        printf ("[4] - usuniecie elementu z drzewa\n");
        printf ("[5] - usuniecie drzewa i nowe drzewo puste\n");
        printf ("[6] - koniec programu\n");
        printf ( "Podaj wybor: " );
        scanf ( "%d", &choice );
        switch ( choice ){
            case 1:
                printf ("Podaj dodawany element: ");
                scanf ( "%d", &value );
                add_new_node ( &tree, value );
                break;
            case 2:
                printf ( "TWOJE DRZEWO:\n" );
                inorder_traversal ( &tree );
                break;
            case 3:
                printf ("Podaj szukany element: ");
                scanf ( "%d", &value );
                temp = seek_node ( &tree, value );
                if ( temp == NULL )  printf ("ELEMENT %d NIE WYSTEPUJE W DRZEWIE\n", value);
                else                 printf ("ELEMENT %d WYSTEPUJE W DRZEWIE\n", value);
                break;
            case 4:
                printf ("Podaj usuwany element: ");
                scanf ( "%d", &value );
                delete_node ( &tree, value );
                break;
            case 5:
                delete_tree ( &tree );
                tree.root = NULL;
                break;
            case 6:
                delete_tree ( &tree );
                break;
            default:
                printf ( "NIEPRAWIDLOWY WYBOR!\n" );
        }
    }
    while ( choice != 6 );

    return 0;
}
