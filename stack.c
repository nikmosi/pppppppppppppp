#include "stack.h"

#include <stdio.h>

char delete(struct stack **head) {
    struct stack *upper;  // создаем левый указатель структурного типа
    char symbol;
    if (*head == NULL) return '\0';  // проверка стека на пустоту
    upper = *head;                   // присваем указатель на начало стека
    symbol = upper->ch;              // записываем операцию в переменную
    *head = upper->next;             // переключение конца стека
    free(upper);                     // удаление предыдущего элемента стека
    return symbol;                   // возврат операции
}

struct stack *push(struct stack *head, char symbol) {
    struct stack *pt;
    pt = malloc(sizeof(struct stack));
    pt->ch = symbol;
    pt->next = head;
    return pt;
}
