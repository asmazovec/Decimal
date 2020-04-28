#include "decimal_1.h"
#include <stdio.h>


sll_int power10 (int a) {
    sll_int b = 1;
    while (a-- > 0) {
        b *= 10;
    }
    return b;
}


decimal_1 normalize (decimal_1 a) {
    while (a.n < 0 && a.num % 10 == 0) {
        a.n++;
        a.num /= 10;
    }
    return a;
}


/* Сложение конечных десятичных дробей. */
decimal_1 summarize (decimal_1 a, decimal_1 b) {
    a = normalize (a);
    b = normalize (b);

    // Привести к общему порядку
    a.num *= power10 (((a.n-b.n)>0)? (a.n-b.n): 0);
    b.num *= power10 (((b.n-a.n)>0)? (b.n-a.n): 0);
    b.n = a.n = ((a.n-b.n)>0)? b.n: a.n;

    // Найти сумму мантисс
    a.num += b.num;
    return normalize (a);
}


/* Разность конечных десятичных дробей. */
decimal_1 subtract (decimal_1 a, decimal_1 b) {
    a = normalize (a);
    b = normalize (b);

    // Привести к общему порядку
    a.num *= power10 (((a.n-b.n)>0)? (a.n-b.n): 0);
    b.num *= power10 (((b.n-a.n)>0)? (b.n-a.n): 0);
    b.n = a.n = ((a.n-b.n)>0)? b.n: a.n;

    // Найти разность мантисс
    a.num -= b.num;
    return normalize (a);
}

/* Перемножение конечных десятичных дробей. */
decimal_1 multiply (decimal_1 a, decimal_1 b) {
    a = normalize (a);
    b = normalize (b);

    // Перемножить мантиссы
    a.num *= b.num;

    // Сложить порядки
    a.n += b.n;
    return normalize (a);
}

