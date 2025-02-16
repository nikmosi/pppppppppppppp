#include "calc.h"

double counter(char *output_str, double x) {
    int n = strlen(output_str);
    double num1;
    double num2;
    double operations[50] = {};
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (output_str[i] == 'x') {
            operations[ptr] = x;
            ptr++;
        } else if (output_str[i] >= '0' && output_str[i] <= '9') {
            operations[ptr] = output_str[i] - '0';
            ptr++;
        } else if (output_str[i] == '+') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 + num2;
            ptr++;
        } else if (output_str[i] == '-') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 - num2;
            ptr++;
        } else if (output_str[i] == '*') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 * num2;
            ptr++;
        } else if (output_str[i] == '/') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            if (num2 != 0) {
                ptr -= 2;
                operations[ptr] = num1 / num2;
                ptr++;
            } else {
                ptr -= 2;
                operations[ptr] = 1000;
                ptr++;
            }
        } else if (output_str[i] == 's') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sin(num1);
        } else if (output_str[i] == 'c') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = cos(num1);
        } else if (output_str[i] == 't') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = tan(num1);
        } else if (output_str[i] == 'g') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = 1 / tan(num1);
        } else if (output_str[i] == 'q') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sqrt(num1);
        } else if (output_str[i] == 'l') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = log(num1);
        }
    }
    ptr--;
    return operations[ptr];
}

void add_func_for_graph(char **graph, int height, int width, char *polish) {
    double mid = height / 2.0 - 0.5;

    for (int x = 0; x < width; x++) {
        int y = round(mid + mid * counter(polish, x / M_PI / 2.0));
        if (y >= 0 && y < 25) graph[y][x] = STAR;
    }
}
