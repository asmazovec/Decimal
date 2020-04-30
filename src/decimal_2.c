/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
*/

#include "decimal_2.h"


/* Нормализация числа.
 * Для числа - конечной десятичной дроби, будут удалены все незначащие 
 * нули и порядок дробной части уменьшится.
 *
 * Пример:
 *      Число A = 123.456000
 *      decimal_2 A = {123, 456000, -6}
 *      normalize (A) = {123, 456, -3}
*/
decimal_2 normalize_2 (decimal_2 a) {
    while (a.n < 0 && a.fract % 10 == 0) {
        a.n++;
        a.fract /= 10;
    }
    return a;
}

/* Чтение decimal_2 из файлового потока
 * dec - указатель на число, в которое сохранятся значения,
 * num - максимальное число символов для чтения, включая нулевой символ,
 * filestream - идентифицирует поток, из которого читаются символы.
*/
decimal_2 get_decimal_2 (decimal_2* dec, int num, FILE* filestream) {
    char input[num];
    char gltoken[num];
    char number[20];

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

    // Беру подстроку после разделителя и приписываю к подстроке перед разделителем.
    token = strtok (NULL, ",.\0");
    strcat (number, (token)? token: "0");


    dec->n = (token)? -strlen (token) +1: 0;
    dec->integ = strtoll (number, NULL, 10) / power10 (-dec->n);
    dec->fract = strtoll (number, NULL, 10) % power10 (-dec->n);
    dec->n = (dec->fract==0)? 0: dec->n;
    *dec = normalize_2 (*dec);
    return *dec;
}


/* Вывод decimal_2 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в который передается поток вывода.
*/
int put_decimal_2 (decimal_2 num, FILE* filestream) {
    int multiplier = (num.integ>=0 && num.fract>=0)? 1: -1;
    return fprintf (filestream, "%c%lld.%0*lld\n",
            (multiplier==1)? '+': '-',
            num.integ * multiplier,
            -num.n,
            num.fract * multiplier);
}


/* Сложение конечных десятичных дробей. */
decimal_2 summarize_2 (decimal_2 a, decimal_2 b) {
    // Привести к общему порядку.
    a.fract *= power10 ((a.n>=b.n)? (a.n-b.n): 0);
    b.fract *= power10 ((b.n>=a.n)? (b.n-a.n): 0);
    b.n = a.n = (a.n<b.n)? a.n: b.n;

    // Отсюда a хранит сумму целых, b сумму дробных частей.
    a.integ += b.integ;
    b.fract += a.fract;

    // Обнулить дробную для a и занять единицу из целой части в дробную. 
    a.fract  = (a.integ>0)? power10 (-a.n): -power10 (-a.n);
    a.integ -= (a.integ>0)? 1: -1;

    // Сложить, прибавить к целым целую часть суммы дробных частей.
    a.fract += b.fract;
    a.integ += a.fract / power10 (-a.n);
    a.fract  = a.fract % power10 (-a.n);
    return normalize_2 (a);
}


/* Разность конечных десятичных дробей. */
decimal_2 subtract_2 (decimal_2 a, decimal_2 b) {
    b.integ *= -1;
    b.fract *= -1;
    return summarize_2 (a, b);
}


/* Перемножение конечных десятичных дробей. */
decimal_2 multiply_2 (decimal_2 a, decimal_2 b) {
    decimal_2 multi = {0, 0, 0};
    decimal_2 tmp;
    
/* Перемножение двух конечных десятичных дробей можно представить в виде:
 * a1.a2 * b1.b2.
 *
 * Или в виде обыкновенных дробей:
 * /         a2    \   /         b2    \
 * | a1 + -------- | * | b1 + -------- |
 * \      10^(a.n) /   \      10^(b.n) / .
 * 
 * Раскроем скобки:
 *             / a1 * b2  \   / a2 * b2  \   /    a2 * b2     \
 *  (a1 * b1)+ | -------- | + | -------- | + | -------------- |
 *             \ 10^(b.n) /   \ 10^(a.n) /   \ 10^(a.n + b.n) / .
 *  
 * Решение для нахождения произведение по данному алгоритму:
 *      где a1  = a.integ;
 *          a2  = a.fract;
 *          a.n = a.n;
 *          b1  = b.integ;
 *          b2  = b.integ;
 *          b.n = b.n.
*/ 
    tmp.integ = a.integ * b.integ;
    tmp.fract = 0;
    tmp.n = 0;

    multi = summarize_2 (multi, tmp);


    tmp.fract = a.integ * b.fract;
    tmp.n = b.n;
    tmp.integ = tmp.fract / power10 (-tmp.n);
    tmp.fract = tmp.fract % power10 (-tmp.n);

    multi = summarize_2 (multi, tmp);


    tmp.fract = a.fract * b.integ;
    tmp.n = a.n;
    tmp.integ = tmp.fract / power10 (-tmp.n);
    tmp.fract = tmp.fract % power10 (-tmp.n);

    multi = summarize_2 (multi, tmp);

    
    tmp.fract = a.fract * b.fract;
    tmp.n = a.n + b.n;
    tmp.integ = tmp.fract / power10 (-tmp.n);
    tmp.fract = tmp.fract % power10 (-tmp.n);

    multi = summarize_2 (multi, tmp);

    return multi;
}
