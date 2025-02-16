#include "polish.h"

void polish_notation(struct stack *operations, char *input_str, char *output_str) {
    int point = 0;
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == ')') {  // выпихиваем в стек предыдущие операции
            while ((operations->ch) != '(')
                output_str[point++] = delete (&operations);  // вынос операции в польскую нотацию
            delete (&operations);                            // удаляем скобку
        }
        if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x')
            output_str[point++] = input_str[i];  // вынос цифр и х в польскую нотацию

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

    while (operations != NULL) output_str[point++] = delete (&operations);  // весь выход формирем тут
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
    int i = 0;
    while (input_string[i]) {
        char token = input_string[i];
        char oper = '0';
        int count = 1;

        if (token == '(' || token == ')')
            oper = token;
        else if (!strncmp(&input_string[i], "sin", 3)) {
            oper = 'S';
            count = 3;
        } else if (!strncmp(&input_string[i], "cos", 3)) {
            oper = 'C';
            count = 3;
        } else if (!strncmp(&input_string[i], "tan", 3)) {
            oper = 'T';
            count = 3;
        } else if (!strncmp(&input_string[i], "ctg", 3)) {
            oper = 'Z';
            count = 3;
        } else if (!strncmp(&input_string[i], "sqrt", 4)) {
            oper = 'Q';
            count = 4;
        } else if (!strncmp(&input_string[i], "ln", 2)) {
            oper = 'L';
            count = 2;
        } else if (strchr("*/+-x", token))
            oper = token;
        else if (token < '0' || token > '9')
            return 0;

        i += count;
    }
    return 1;
}
