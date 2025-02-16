#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack {
    char ch;
    struct stack *next;
};

void print(struct stack *head);
char delete(struct stack **head);
struct stack *push(struct stack *, char);

#endif
