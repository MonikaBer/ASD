#ifndef DEC_H
#define DEC_H

struct el_FIFO{
  int x;
  struct el_FIFO *next;
};

struct FIFO{
  struct el_FIFO *begin;
  struct el_FIFO *end;
};

struct FIFO* create_empty_FIFO ();
struct el_FIFO* create_new_el_FIFO ( int value );

struct FIFO* push_back ( struct FIFO *queue, int value );
struct FIFO* pop_front ( struct FIFO *queue );
struct FIFO* delete_FIFO ( struct FIFO *queue );
struct FIFO* print_FIFO ( struct FIFO *queue );

#endif
