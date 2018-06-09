#ifndef DEC_H
#define DEC_H

struct el_list {
    int x;
    struct el_list* next;
};


struct el_list* create_new_el (int element);
struct el_list* seek_position (struct el_list *list, int position);
struct el_list* seek_value (struct el_list *list, int value);
void insert_after (struct el_list *temp, struct el_list *new_el);
struct el_list* find_pointer_on_previous_element (struct el_list *list, struct el_list *temp);

void print_first_element (struct el_list *list);
struct el_list* push_on_position (struct el_list *list, int element, int position);
struct el_list* push_after_value (struct el_list *list, int element, int value);
struct el_list* delete (struct el_list *list, struct el_list *temp);
struct el_list* pop_from_position (struct el_list *list, int position);
struct el_list* pop_value (struct el_list *list, int value);
void print_from_beginning (struct el_list *list);
int seek_element_in_list (struct el_list *list, int value);
void delete_list (struct el_list *list);

#endif
