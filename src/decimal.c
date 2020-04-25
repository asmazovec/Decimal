#include "decimal.h"

decimal summarize(decimal a, decimal b) {
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
    return a;
}

decimal subtract(decimal a, decimal b) {
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
    
    return a;
}
