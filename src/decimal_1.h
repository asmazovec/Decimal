#ifndef DECIMAL_1_H_
#define DECIMAL_1_H_

/* Первый вариант реализации конечных десятичных дробей на си
 *
 * Структура конечной десятичной дроби:
 *      1. Число, хранящее и дробную и целую части числа,
 *      2. Степень 10, определяющая число знаков после запятой.
 * 
 * Пример:
 *      Число A = 123.456
 *      decimal_1 A = {123456, -3};
*/ 
typedef 
typedef 

typedef struct {
    signed long long int num;   // Мантисса 
    signed char n;              // Порядок 
} decimal_1;


sll_int power10 (int);

// decimal normalize (decimal_1);

decimal_1 summarize (decimal_1, decimal_1);
decimal_1 subtract (decimal_1, decimal_1);
decimal_1 multiply (decimal_1, decimal_1);


#endif /*DECIMAL_1_H_*/
