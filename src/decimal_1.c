/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
*/

#include "decimal_1.h"


// Возведение 10 в натуральную степень a (и 0). 
signed long long int power10 (int a) {
    signed long long int b = 1;
    while (a-- > 0) {
        b *= 10;
    }
    return b;
}


/* Нормализация числа.
 * Для мантиссы, содержащей незначащие нули в "дробной части" будут удалены
 * все незначащие нули и порядок дробной части уменьшится.
 * 
 * Пример:
 *      Число А = 123.456000 
 *      decimal_1 A = {123456000, -6}
 *      normalize (A) = {123456, -3}
*/ 
decimal_1 normalize (decimal_1 a) {
    while (a.n < 0 && a.num % 10 == 0) {
        a.n++;
        a.num /= 10;
    }
    return a;
}


/* Чтение decimal_1 из файлового потока
 * dec - указатель на число, в которое сохранятся значения,
 * num - максимальное число символов для чтения, включая нулевой символ,
 * filestream - идентифицирует поток, из которого читаются символы.
 */ 
decimal_1 get_decimal_1 (decimal_1* dec, int num, FILE* filestream) {   
}


/* Вывод decimal_2 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в который передается поток вывода.
*/
char* put_decimal_1 (decimal_1 num, FILE* filestream) {
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

