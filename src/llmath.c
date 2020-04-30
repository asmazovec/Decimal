/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
 *
 ********************************************************
 * Функции для работы с типом long long
 ********************************************************/


#include "llmath.h"


/* Возведение 10 в натуральную степень a. */
sll_int power10 (int a) {
    sll_int b = 1;
    while (a-- > 0) {
        b *= 10;
    }
    return b;
}
