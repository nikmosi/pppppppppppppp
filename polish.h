#ifndef POLISH_H
#define POLISH_H

#include <string.h>

#include "stack.h"

int check_input(char *input_string);
int priority(char);
void process_operator(struct stack **operations, char op, char *output_str, int *point);
char get_function(char *input_str, int *index);
char get_operator(char *p, int *index, int *count);
void polish_notation(struct stack *operations, char *input_str, char *output_str);

#endif  // !POLISH_H
