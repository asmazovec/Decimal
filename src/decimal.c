#include "decimal.h"


decimal normalize (decimal a) {
    for (int i = a.n; i < 0; i++) {
        if (a.num % 10 == 0) {
            a.num /= 10;
        } else {
            break;
        }
    }
    return a;
}


decimal summarize (decimal a, decimal b) {
    // Привести к общему порядку
    if (a.n > b.n) {
        for (int i = 0; i < a.n - b.n; i++) {
            a.num *= 10;
        }
        a.n = b.n;
    } else {
        for (int i = 0; i < a.n - b.n; i++) {
            b.num *= 10;
        }
        a.n = b.n;
    }

    a.num += b.num;
    normalize(a);
    return a;
}


decimal subtract (decimal a, decimal b) {
    // Привести к общему порядку
    if (a.n > b.n) {
        for (int i = 0; i < a.n - b.n; i++) {
            a.num *= 10;
        }
        a.n = b.n;
    } else {
        for (int i = 0; i < a.n - b.n; i++) {
            b.num *= 10;
        }
        a.n = b.n;
    }

    a.num -= b.num;
    normalize(a);
    return a;
}


decimal multiply (decimal a, decimal b) {
    // Перемножить мантиссы
    a.num *= b.num;

    // Сложить порядки
    a.n += b.n;
    normalize(a);
    return a;
}

