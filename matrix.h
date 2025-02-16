#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

char **malloc_matrix(int height, int width);
void draw_graph(char **graph, int height);
void free_matrix(char **graph, int height);
void init_graph(char **matrix, int height, int width, char dot);

#endif  // !MATRIX_H
