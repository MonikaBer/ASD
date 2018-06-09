#ifndef DEC_H
#define DEC_H

struct el_list {
    int x;
    struct el_list* next;
};

struct oneway_list {
    struct el_list* begin;
    struct el_list* end;
};

struct el_list* create_new_el (int element);
struct oneway_list* constructor_of_empty_list();
struct el_list* seek_position (struct oneway_list *list, int position);
struct el_list* seek_value (struct oneway_list *list, int value);
void insert_after (struct el_list *temp, struct el_list *new_el);
struct oneway_list* insert_after_last (struct oneway_list* list, struct el_list *temp, struct el_list *new_el);
struct oneway_list* insert_before_first (struct oneway_list* list, struct el_list *temp, struct el_list *new_el);
struct el_list* find_pointer_on_previous_element (struct oneway_list *list, struct el_list *temp);

struct oneway_list* push_on_position (struct oneway_list *list, int element, int position);
struct oneway_list* push_after_value (struct oneway_list *list, int element, int value);
struct oneway_list* delete (struct oneway_list *list, struct el_list* temp);
struct oneway_list* pop_from_position (struct oneway_list *list, int position);
struct oneway_list* pop_value (struct oneway_list *list, int value);
void print_from_beginning (struct oneway_list *list);
int seek_element_in_list (struct oneway_list *list, int value);
void delete_list (struct oneway_list *list);

#endif
