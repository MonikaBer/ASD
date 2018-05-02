#ifndef DEC_H
#define DEC_H

struct student {
    int nr;
    float deg;
};

void data ( student *students, int n );
int sort01 ( student *students, int n );
void print ( student *students, int n, int result );

#endif
