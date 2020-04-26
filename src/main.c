#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "decimal.h"

int main() {
    char input_s[256];
    char number[20];
    char* token;

    decimal a;
    decimal b;

    
    ///// 1 Число
    printf("Введите a\n>>> ");
    fgets(input_s, 256, stdin);    
    token = strtok (input_s, "., ");
    strcpy (number, token);
    
    token = strtok (NULL, "., ");
    strcat (number, token);

    a.n = -strlen (token)+1;
    a.num = strtoll (number, NULL, 10);


    ///// 2 Число
    printf("Введите b\n>>> ");
    fgets(input_s, 256, stdin);    
    token = strtok (input_s, "., ");
    strcpy (number, token);
    
    token = strtok (NULL, "., ");
    strcat (number, token);

    b.n = -strlen (token)+1;
    b.num = strtoll (number, NULL, 10);



    //// Вычисления
    decimal res;

    res = summarize (a, b);         ////// ++++++++++++++++++
    printf ("a + b = %+lld.%lld\n",
            res.num / power10 (-res.n), 
            res.num % power10 (-res.n) * ((res.num<0)? -1: 1));


    res = subtract (a, b);
    printf ("a - b = %+lld.%lld\n", ////// ------------------
            res.num / power10 (-res.n), 
            res.num % power10 (-res.n) * ((res.num<0)? -1: 1));


    res = multiply (a, b);
    printf ("a * b = %+lld.%lld\n", ////// ******************
            res.num / power10 (-res.n), 
            res.num % power10 (-res.n) * ((res.num<0)? -1: 1));


    return 0;
}
