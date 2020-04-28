/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
*/

#include "decimal_2.h"


// Возведение 10 в натуральную степень a (и 0).
signed long long int power10 (int a) {
    signed long long int b = 1;
    while (a-- > 0) {
        b *= 10;
    }
    return b;
}


/* Чтение decimal_2 из файлового потока
 * dec - указатель на число, в которое сохранятся значения,
 * num - максимальное число символов для чтения, включая нулевой символ,
 * filestream - идентифицирует поток, из которого читаются символы.
*/
decimal_2 get_decimal_2 (decimal_2* dec, int num, FILE* filestream) {
}


/* Вывод decimal_2 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в который передается поток вывода.
*/
char* put_decimal_2 (decimal_2 num, FILE* filestream) {
}


/* Сложение конечных десятичных дробей. */
decimal_2 summarize (decimal_2 num, FILE* filestream) {
}


/* Разность конечных десятичных дробей. */
decimal_2 subtract (decimal_2 a, decimal_2 b) {
}

/* Перемножение конечных десятичных дробей. */
decimal_2 multiply (decimal_2 a, decimal_2 b) {
}





