#ifndef DEC_H
#define DEC_H

struct el_LIFO {
  int x;
  struct el_LIFO* next;
};

struct el_LIFO* empty_LIFO ( struct el_LIFO *top_LIFO );
struct el_LIFO* push ( struct el_LIFO *top_LIFO, int value );
struct el_LIFO* pop ( struct el_LIFO *top_LIFO );
int print_top ( struct el_LIFO *top_LIFO );
struct el_LIFO* print_LIFO ( struct el_LIFO *top_LIFO );

#endif
