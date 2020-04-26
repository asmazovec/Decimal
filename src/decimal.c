#include "decimal.h"
#include <stdio.h>

sll_int power10 (int a) {
    sll_int b = 1;
    while (a-- > 0) {
        b *= 10;
    }
    return b;
}


decimal normalize (decimal a) {
    while (a.n < 0 && a.num % 10 == 0) {
        a.n++;
        a.num /= 10;
    }
    return a;
}


decimal summarize (decimal a, decimal b) {
    a = normalize (a);
    b = normalize (b);

    // Привести к общему порядку
    a.num *= power10 (((a.n-b.n)>0)? (a.n-b.n): 0);
    b.num *= power10 (((b.n-a.n)>0)? (b.n-a.n): 0);
    b.n = a.n = ((a.n-b.n)>0)? b.n: a.n;

    a.num += b.num;
    return normalize (a);
}


decimal subtract (decimal a, decimal b) {
    a = normalize (a);
    b = normalize (b);

    // Привести к общему порядку
    a.num *= power10 (((a.n-b.n)>0)? (a.n-b.n): 0);
    b.num *= power10 (((b.n-a.n)>0)? (b.n-a.n): 0);
    b.n = a.n = ((a.n-b.n)>0)? b.n: a.n;

    a.num -= b.num;
    return normalize (a);
}


decimal multiply (decimal a, decimal b) {
    a = normalize (a);
    b = normalize (b);

    // Перемножить мантиссы
    a.num *= b.num;

    // Сложить порядки
    a.n += b.n;
    return normalize (a);
}

