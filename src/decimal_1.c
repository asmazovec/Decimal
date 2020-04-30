/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
*/

#include "decimal_1.h"


/* Нормализация числа.
 * Для мантиссы, содержащей незначащие нули в "дробной части" будут удалены
 * все незначащие нули и порядок дробной части уменьшится.
 * 
 * Пример:
 *      Число А = 123.456000 
 *      decimal_1 A = {123456000, -6}
 *      normalize_1 (A) = {123456, -3}
*/ 
decimal_1 normalize_1 (decimal_1 a) {
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
    char input[num];
    char gltoken[num];
    char number[20];
    int ch;

    fgets (input, num, filestream);
    strcpy (gltoken, input);    // Дублирую строку, чтобы не испортить на шаге определения знака.

    // Определяю знак числа (получаю лексему только из минусов).
    gltoken[0] = (strtok (gltoken, "+0123456789., ") [0] == '-')? '-': '+';  
    // Гарантирую, что перед запятой в записи будет число - незначимый ноль.
    gltoken[1] = '0';
    gltoken[2] = '\0';

    // Вырезаю из строки подстроку, содержащую число. 
    strcat (gltoken, strtok (input, "+- ="));   // + и - экранируют начало лексемы от лишних разделителей

    // Беру подстроку перед разделителем. 
    char* token = strtok (gltoken, ",.");
    strcpy (number, (token)? token: "0");

    // Беру подстроку после разделителя.
    token = strtok (NULL, ",.\0");
    strcat (number, (token)? token: "0");


    dec->n = (token)? -strlen (token) +1: 0;    // Число знаков после запятой.
    dec->num = strtoll (number, NULL, 10);  // Значение мантиссы.
    *dec = normalize_1 (*dec);
    return *dec;
}


/* Вывод decimal_1 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в который передается поток вывода.
*/
int put_decimal_1 (decimal_1 num, FILE* filestream) {
    int multiplier = (num.num>=0)? 1: -1;
    num.num *= multiplier;
    return fprintf (filestream, "%c%lld.%0*lld\n",
            (multiplier==1)? '+': '-',
            num.num / power10 (-num.n),
            -num.n,
            num.num % power10 (-num.n));
}


/* Сложение конечных десятичных дробей. */
decimal_1 summarize_1 (decimal_1 a, decimal_1 b) {
    // Привести к общему порядку.
    a.num *= power10 ((a.n>=b.n)? (a.n-b.n): 0);
    b.num *= power10 ((b.n>=a.n)? (b.n-a.n): 0);
    b.n = a.n = (a.n<b.n)? a.n: b.n;

    // Найти сумму мантисс.
    a.num += b.num;
    return normalize_1 (a);
}


/* Разность конечных десятичных дробей. */
decimal_1 subtract_1 (decimal_1 a, decimal_1 b) {
    b.num *= -1;
    return summarize_1 (a, b);
}


/* Перемножение конечных десятичных дробей. */
decimal_1 multiply_1 (decimal_1 a, decimal_1 b) {
    // Перемножить мантиссы.
    a.num *= b.num;

    // Сложить порядки.
    a.n += b.n;
    return normalize_1 (a);
}

