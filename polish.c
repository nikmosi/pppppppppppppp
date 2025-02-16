#include "polish.h"

void polish_notation(struct stack *operations, const char *input_str, char *output_str) {
    int point = 0;
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == ')') {
            while ((operations->ch) != '(') output_str[point++] = delete (&operations);
            delete (&operations);
        }
        if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x')
            output_str[point++] = input_str[i];

        char symbol;
        int offset = 0;
        int is_simple = 0;

        if (strncmp(&input_str[i], "sin", 3) == 0) {
            symbol = 's';
            offset = 3;
        } else if (strncmp(&input_str[i], "cos", 3) == 0) {
            symbol = 'c';
            offset = 3;
        } else if (strncmp(&input_str[i], "tan", 3) == 0) {
            symbol = 't';
            offset = 3;
        } else if (strncmp(&input_str[i], "ctg", 3) == 0) {
            symbol = 'g';
            offset = 3;
        } else if (strncmp(&input_str[i], "sqrt", 4) == 0) {
            symbol = 'q';
            offset = 4;
        } else if (strncmp(&input_str[i], "ln", 2) == 0) {
            symbol = 'l';
            offset = 2;
        } else if (strchr("+-/*", input_str[i])) {
            symbol = input_str[i];
            is_simple = 1;
        }

        if (offset != 0 || is_simple) {
            if (operations == NULL) {
                operations = push(operations, symbol);
            } else if (priority(operations->ch) < priority(symbol))
                operations = push(operations, symbol);
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority(symbol)))
                    output_str[point++] = delete (&operations);
                operations = push(operations, symbol);
            }
            i += offset;
        }

        if (input_str[i] == '(') operations = push(operations, '(');
    }

    while (operations != NULL) output_str[point++] = delete (&operations);
    output_str[point] = '\0';
}

int priority(char symbol) {
    switch (symbol) {
        case 'c':
        case 's':
        case 't':
        case 'g':
        case 'q':
        case 'l':
            return 4;
        case '*':
        case '/':
            return 3;

        case '-':
        case '+':
            return 2;

        case '(':
            return 1;
    }
    return 0;
}

int check_input(char *input_string) {
    const char *p = input_string;
    int i = 0;
    int res = 1;
    while (p[i]) {
        char oper;
        int count;

        if (p[i] == '(') {
            oper = '(';
            count = 1;
        } else if (p[i] == ')') {
            oper = ')';
            count = 1;
        } else if (p[i] == 's' && p[i + 1] == 'i' && p[i + 2] == 'n') {
            oper = 'S';
            count = 3;
        } else if (p[i] == 'c' && p[i + 1] == 'o' && p[i + 2] == 's') {
            oper = 'C';
            count = 3;
        } else if (p[i] == 't' && p[i + 1] == 'a' && p[i + 2] == 'n') {
            oper = 'T';
            count = 3;
        } else if (p[i] == 'c' && p[i + 1] == 't' && p[i + 2] == 'g') {
            oper = 'Z';
            count = 3;
        } else if (p[i] == 's' && p[i + 1] == 'q' && p[i + 2] == 'r' && p[i + 3] == 't') {
            oper = 'Q';
            count = 4;
        } else if (p[i] == 'l' && p[i + 1] == 'n') {
            oper = 'L';
            count = 2;
        } else if (p[i] == '*') {
            oper = '*';
            count = 1;
        } else if (p[i] == '/') {
            oper = '/';
            count = 1;
        } else if (p[i] == '+') {
            oper = '+';
            count = 1;
        } else if (p[i] == '-') {
            oper = '-';
            count = 1;
        } else if (p[i] == 'x') {
            oper = 'x';
            count = 1;
        } else {
            oper = '0';
        }

        if (oper != '0') {
            i += count;
        } else {
            if (p[i] < '0' || p[i] > '9') {
                res = 0;
                break;
            }
            i++;
        }
    }
    return res;
}
