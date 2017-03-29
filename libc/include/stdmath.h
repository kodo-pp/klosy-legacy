//Как функции для рисования написать? Есть решение, хоть и не очень хорошее, но об этих функциях чуть позже. Хотя нет, давай их сделаем первыми, чтобы мы могли на это посмотреть
#ifndef MATH_H
#define MATH_H

// Что? что? ничего
#include <stdlib.h>
#include <trigonometric_functions.h>

double sqrt(double);
double abs(double);
void draw_point(int, int);
void draw_line(int, int, int, int);
int round(double);

#endif
