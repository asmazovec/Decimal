/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
 *
 **************************************************************
 * Второй вариант реализации конечных десятичных дробей на си
 *
 * Структура конечной десятичной дроби:
 *      1. Число, хранящее целую часть числа,
 *      2. Число, хранящее дробную часть числа,
 *      3. Степень 10, определяющая число знаков после запятой.
 * 
 * Пример:
 *      Число А = 123.056
 *      decimal_2 A = {123, 56, -3};
 **************************************************************/


#ifndef DECIMAL_2_H_
#define DECIMAL_2_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    signed long long integ;  // integer - целая часть
    signed long long fract;  // fractional - дробная часть
    signed char n;           // степень, число знаков после запятой
} decimal_2;


/* Чтение decimal_2 из файлового потока.
 * dec - указатель на число, в которое сохранятся значения,
 * num - максимальное число символов для чтения, включая нулевой символ,
 * filestream - идентифицирует поток, из которого читаются символы.
*/
decimal_2 get_decimal_2 (decimal_2* dec, int num, FILE* filestream);


/* Вывод decimal_2 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в которой передается поток вывода.
*/
char* put_decimal_2 (decimal_2 num, FILE* filestream);


decimal_2 summarize_2 (decimal_2, decimal_2); // сумма
decimal_2 subtract_2 (decimal_2, decimal_2);  // разность
decimal_2 multiply_2 (decimal_2, decimal_2);  // произведение


#endif /*DECIMAL_2_H_*/
