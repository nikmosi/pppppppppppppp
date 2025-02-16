#include "stack.h"

#include <stdio.h>

char delete(struct stack **head) {
    struct stack *upper;
    char symbol;
    if (*head == NULL) return '\0';
    upper = *head;
    symbol = upper->ch;
    *head = upper->next;
    free(upper);
    return symbol;
}

struct stack *push(struct stack *head, char symbol) {
    struct stack *pt;
    pt = malloc(sizeof(struct stack));
    pt->ch = symbol;
    pt->next = head;
    return pt;
}
