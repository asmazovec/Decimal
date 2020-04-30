/* MIT License
 * Copyright (c) 2020 Alexander Mazovets
 *
 **************************************************************
 * Первый вариант реализации конечных десятичных дробей на си
 *
 * Структура конечной десятичной дроби:
 *      1. Число, хранящее и дробную и целую части числа,
 *      2. Степень 10, определяющая число знаков после запятой.
 * 
 * Пример:
 *      Число A = 123.056
 *      decimal_1 A = {123456, -3};
 **************************************************************/ 


#ifndef DECIMAL_1_H_
#define DECIMAL_1_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llmath.h"


typedef struct {
    sll_int num;     // Мантисса 
    signed char n;   // Порядок 
} decimal_1;


/* Чтение decimal_1 из файлового потока. 
 * dec - указатель на число, в которое сохранятся значения,
 * num - максимальное число символов для чтения, включая нулевой символ,
 * filestream - идентифицирует поток, из которого читаются символы.
*/
decimal_1 get_decimal_1 (decimal_1* dec, int num, FILE* filestream);


/* Вывод decimal_1 в файловый поток.
 * num - конечная десятичная дробь, которая будет выведена в файловый поток,
 * filestream - идентифицирует поток, в который передается поток вывода.
*/
int put_decimal_1 (decimal_1 num, FILE* filestream);


decimal_1 summarize_1 (decimal_1, decimal_1);   // Сумма
decimal_1 subtract_1 (decimal_1, decimal_1);    // Разность
decimal_1 multiply_1 (decimal_1, decimal_1);    // Произведение


#endif /*DECIMAL_1_H_*/
