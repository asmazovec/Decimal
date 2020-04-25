#include <stdio.h>
#include "decimal.h"

int main() {
    decimal a = {11111, -2};
    decimal b = {11111, -3};

    printf("%lldE%d\n", summarize(a, b).num, summarize(a, b).n);
    printf("%lldE%d\n", subtract(a, b).num, subtract(a, b).n);
    printf("%lldE%d\n", multiply(a, b).num, multiply(a, b).n);

    decimal c = {101000, -5};
    printf("%lldE%d\n", normalize(c).num, normalize(c).n);

    decimal d = {10000000, -5};
    printf("%lldE%d\n", normalize(d).num, normalize(d).n);
    
    return 0;
}
