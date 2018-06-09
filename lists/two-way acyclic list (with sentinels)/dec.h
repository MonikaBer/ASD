#ifndef DEC_H
#define DEC_H

struct el_list {
    int x;
    struct el_list* right;
    struct el_list* left;
};

struct twoway_list {
    struct el_list* begin;
    struct el_list* end;
};

struct el_list* create_new_el (int element);
struct twoway_list* constructor_of_empty_list();
struct el_list* seek_position (struct twoway_list *list, int position);
struct el_list* seek_value (struct twoway_list *list, int value);
void insert_after ( struct twoway_list* list, struct el_list *temp, struct el_list *new_el );
void push_on_position (struct twoway_list *list, int element, int position);
void push_after_value (struct twoway_list *list, int element, int value);
void delete (struct twoway_list *list, struct el_list* temp);
void pop_from_position (struct twoway_list *list, int position);
void pop_value (struct twoway_list *list, int value);
void print_from_beginning (struct twoway_list *list);
void print_from_end (struct twoway_list *list);
int seek_element_in_list (struct twoway_list *list, int value);
void delete_list (struct twoway_list *list);

#endif
