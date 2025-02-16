#ifndef POLISH_H
#define POLISH_H

#include <string.h>

#include "stack.h"

int check_input(char *input_string);
int priority(char);
void polish_notation(struct stack *operations, const char *input_str, char *output_str);

#endif  // !POLISH_H
