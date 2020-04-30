/* MIT License
 *
 * Copyright (c) 2020 Alexander Mazovets
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decimal_1.h"
#include "decimal_2.h"


int main() {
    int key = 0;
    printf ("    Эта программа производит вычисления (находит сумму, разность" 
            "и произведение) для двух чисел - конечных десятичных дробей.\n"
            "    Программа предоставляет два варианта представления конечных "
            "десятичных дробей:\n"
            "        1. Дробь представляется в виде {число, степень десяти}, что"
            "    соответствует математической записи десятичной дроби в виде"
            "    обыкновенной дроби.\n"
            "        2. Дробь представляется в виде"
            "    {целая часть, дробная часть, степень 10}.\n\n\n"
            );
    

    do { /* while (key != 5) */
        printf ("Выберите вариант представления конечных десятичных дробей (5 - выход): ");
        do {
            scanf ("%i", &key);
            if ((key<1 || key>2) && key!=5) {
                printf ("\nОшибка ввода - выберите значение 1 или 2\n"
                        "Повторите попытку (5 - выход): ");
            }
        } while ((key<1 || key>2) && key!=5);
        printf ("\n\n");
        while (getchar() != '\n'); 
    

        if (key==1) {
            decimal_1 a_1;
            decimal_1 b_1;

            printf ("Выбран первый вариант. \n");
            printf ("Введите a >>> \0");
            get_decimal_1 (&a_1, 122, stdin);
        
            printf ("Введите b >>> \0");
            get_decimal_1 (&b_1, 256, stdin);
    
            printf ("\ta + b = "), put_decimal_1 (summarize_1 (a_1, b_1), stdout);
            printf ("\ta - b = "), put_decimal_1 (subtract_1 (a_1, b_1), stdout);
            printf ("\ta * b = "), put_decimal_1 (multiply_1 (a_1, b_1), stdout);

        } 

        if (key==2) {
            decimal_2 a_2;
            decimal_2 b_2;

            printf ("Выбран второй вариант. \n");
            printf ("Введите a >>> ");
            get_decimal_2 (&a_2, 256, stdin);

            printf ("Введите b >>> ");
            get_decimal_2 (&b_2, 256, stdin);
    
            printf ("\ta + b = "), put_decimal_2 (summarize_2 (a_2, b_2), stdout);
            printf ("\ta - b = "), put_decimal_2 (subtract_2 (a_2, b_2), stdout);
            printf ("\ta * b = "), put_decimal_2 (multiply_2 (a_2, b_2), stdout);
        }

        printf ("\n\n");
    } while (key != 5);

    return 0;
}
