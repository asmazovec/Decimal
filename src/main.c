#include <stdio.h>
#include "decimal.h"

int main() {
    decimal a = {11111, -2};
    decimal b = {-11111, -3};

    printf("%lldE%d\n", summarize(a, b).num, summarize(a, b).n);
    return 0;
}
